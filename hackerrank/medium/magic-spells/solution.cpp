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
