# Magic Spells

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

While playing a video game, you are battling a powerful dark wizard. He casts his spells from a distance, giving you only a few seconds to react and conjure your counterspells. For a counterspell to be effective, you must first identify what kind of spell you are dealing with.

The wizard uses scrolls to conjure his spells, and sometimes he uses some of his generic spells that restore his stamina. In that case, you will be able to extract the name of the scroll from the spell. Then you need to find out how similar this new spell is to the spell formulas written in your spell journal.

Spend some time reviewing the locked code in your editor, and complete the body of the *counterspell* function.

Check [Dynamic cast](http://en.cppreference.com/w/cpp/language/dynamic_cast) to get an idea of how to solve this challenge.

**Input Format**

The wizard will read $t$ scrolls, which are hidden from you.  
Every time he casts a spell, it's passed as an argument to your *counterspell* function.

**Constraints**

- $1 \le t \le 100$  
- $1 \le |s| \le 1000$, where $s$ is a scroll name.
- Each scroll name, $s$, consists of uppercase and lowercase letters.

**Output Format**

After identifying the given spell, print its name and power.  
If it is a generic spell, find a subsequence of letters that are contained in both the spell name and your spell journal. 
Among all such subsequences, find and print the length of the longest one on a new line.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-30T19:35:48.731Z  

```cpp
#include <iostream>
#include <string>
using namespace std;

class Spell
{
private:
    string scrollName;

public:
    Spell()
    {
        scrollName = "";
    }

    Spell(string name)
    {
        scrollName = name;
    }

    virtual ~Spell() {}

    string revealScrollName()
    {
        return scrollName;
    }
};

class Fireball : public Spell
{
private:
    int power;

public:
    Fireball(int power) : power(power) {}

    void revealFirepower()
    {
        cout << "Fireball: " << power << '\n';
    }
};

class Frostbite : public Spell
{
private:
    int power;

public:
    Frostbite(int power) : power(power) {}

    void revealFrostpower()
    {
        cout << "Frostbite: " << power << '\n';
    }
};

class Thunderstorm : public Spell
{
private:
    int power;

public:
    Thunderstorm(int power) : power(power) {}

    void revealThunderpower()
    {
        cout << "Thunderstorm: " << power << '\n';
    }
};

class Waterbolt : public Spell
{
private:
    int power;

public:
    Waterbolt(int power) : power(power) {}

    void revealWaterpower()
    {
        cout << "Waterbolt: " << power << '\n';
    }
};

class SpellJournal
{
public:
    static string journal;

    static string read()
    {
        return journal;
    }
};

string SpellJournal::journal = "";

void counterspell(Spell *spell)
{
    // Known spells
    if (Fireball *p = dynamic_cast<Fireball*>(spell))
    {
        p->revealFirepower();
        return;
    }

    if (Frostbite *p = dynamic_cast<Frostbite*>(spell))
    {
        p->revealFrostpower();
        return;
    }

    if (Thunderstorm *p = dynamic_cast<Thunderstorm*>(spell))
    {
        p->revealThunderpower();
        return;
    }

    if (Waterbolt *p = dynamic_cast<Waterbolt*>(spell))
    {
        p->revealWaterpower();
        return;
    }

    // Generic spell
    string spellName = spell->revealScrollName();
    string journal = SpellJournal::read();

    int n = spellName.size();
    int m = journal.size();

    // 1D LCS
    int dp[1001] = {};

    for (int i = 1; i <= n; ++i)
    {
        int diagonal = 0;

        for (int j = 1; j <= m; ++j)
        {
            int previous = dp[j];

            if (spellName[i - 1] == journal[j - 1])
            {
                dp[j] = diagonal + 1;
            }
            else if (dp[j - 1] > dp[j])
            {
                dp[j] = dp[j - 1];
            }

            diagonal = previous;
        }
    }

    cout << dp[m] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        string type;
        int power;

        cin >> type >> power;

        Spell *spell = nullptr;

        if (type == "fire")
        {
            spell = new Fireball(power);
        }
        else if (type == "frost")
        {
            spell = new Frostbite(power);
        }
        else if (type == "water")
        {
            spell = new Waterbolt(power);
        }
        else if (type == "thunder")
        {
            spell = new Thunderstorm(power);
        }
        else
        {
            // Generic spell
            spell = new Spell(type);

            cin >> SpellJournal::journal;
        }

        counterspell(spell);

        delete spell;
    }

    return 0;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/magic-spells/problem)