

#include "TennisLog.h"
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
namespace sdds
{
    TennisMatch::TennisMatch()
    {
        t_match_id = 0;
        t_tournament_name = nullptr;
        t_tournament_id = nullptr;
        t_loser = nullptr;
        t_winner = nullptr;
    }

    TennisMatch::TennisMatch(const char *tournamentID, const char *tournamentName, int matchID, const char *matchWinner, const char *matchLoser)
    {
        t_match_id = matchID;
        t_tournament_name = new char[strlen(tournamentName) + 1];
        t_tournament_id = new char[strlen(tournamentID) + 1];
        t_loser = new char[strlen(matchLoser) + 1];
        t_winner = new char[strlen(matchWinner) + 1];
        strcpy(t_tournament_name, tournamentName);
        strcpy(t_tournament_id, tournamentID);
        strcpy(t_loser, matchLoser);
        strcpy(t_winner, matchWinner);
    }

    ostream &operator<<(ostream &os, const TennisMatch &TMatch)
    {
        if (TMatch.t_tournament_id != nullptr)
        {
            os << setw(20) << setfill('.')
               << right << "Tourney ID"
               << " : " << setw(30)
               << setfill('.') << left
               << TMatch.t_tournament_id << endl;
            os << setw(20) << setfill('.')
               << right << "Match ID"
               << " : " << setw(30)
               << setfill('.') << left
               << TMatch.t_match_id << endl;
            os << setw(20) << setfill('.')
               << right << "Tourney"
               << " : " << setw(30)
               << setfill('.') << left
               << TMatch.t_tournament_name << endl;
            os << setw(20) << setfill('.')
               << right << "Winner"
               << " : " << setw(30)
               << left << TMatch.t_winner << endl;
            os << setw(20) << setfill('.')
               << right << "Loser"
               << " : " << setw(30)
               << left << TMatch.t_loser << endl;
        }
        else
        {
            os << "Empty Match";
        }
        cout << setfill(' ');
        return os;
    }

    TennisLog::TennisLog()
    {
        tennis_matches = nullptr;
        m_num_of_matches = 0;
    }

    TennisLog::TennisLog(const TennisLog &Tlog)
    {
        tennis_matches = new TennisMatch[Tlog.m_num_of_matches];
        m_num_of_matches = Tlog.m_num_of_matches;
        for (size_t i = 0; i < m_num_of_matches; i++)
        {
            TennisMatch match(
                              Tlog.tennis_matches[i].t_tournament_id,
                              Tlog.tennis_matches[i].t_tournament_name,
                              Tlog.tennis_matches[i].t_match_id,
                              Tlog.tennis_matches[i].t_winner,
                              Tlog.tennis_matches[i].t_loser
                              );
            tennis_matches[i] = match;
        }
    }

    TennisLog &TennisLog::operator=(const TennisLog &Tlog)
    {
        if (this != &Tlog)
        {
            if (tennis_matches != nullptr)
            {
                this->~TennisLog();
            }
            m_num_of_matches = Tlog.m_num_of_matches;
            tennis_matches = new TennisMatch[m_num_of_matches];
            for (size_t i = 0; i < m_num_of_matches; i++)
            {
                TennisMatch match(
                                  Tlog.tennis_matches[i].t_tournament_id,
                                  Tlog.tennis_matches[i].t_tournament_name,
                                  Tlog.tennis_matches[i].t_match_id,
                                  Tlog.tennis_matches[i].t_winner,
                                  Tlog.tennis_matches[i].t_loser
                                  );
                tennis_matches[i] = match;
            }
        }
        return *this;
    }

    TennisLog::TennisLog(TennisLog &&Tlog)
    {
        tennis_matches = nullptr;
        *this = move(Tlog);
        Tlog.tennis_matches = nullptr;
        Tlog.m_num_of_matches = 0;
    }

    TennisLog &TennisLog::operator=(TennisLog &&Tlog)
    {
        if (this != &Tlog)
        {
            if (tennis_matches != nullptr)
            {
                this->~TennisLog();
            }
            m_num_of_matches = Tlog.m_num_of_matches;
            tennis_matches = Tlog.tennis_matches;
            Tlog.tennis_matches = nullptr;
            Tlog.m_num_of_matches = 0;
        }
        return *this;
    }

    TennisLog::~TennisLog()
    {
        for (size_t i = 0; i < m_num_of_matches; i++)
        {
            delete[] tennis_matches[i].t_tournament_id;
            delete[] tennis_matches[i].t_tournament_name;
            tennis_matches[i].t_match_id = 0;
            delete[] tennis_matches[i].t_winner;
            delete[] tennis_matches[i].t_loser;
        }
        delete[] tennis_matches;
    }

    TennisLog::operator size_t() const
    {
        return m_num_of_matches;
    }

    TennisMatch TennisLog::operator[](size_t i)
    {
        TennisMatch Tmatch;
        if (m_num_of_matches >= 1 && i < m_num_of_matches)
        {
            Tmatch = tennis_matches[i];
        }
        return Tmatch;
    }

    TennisLog::TennisLog(const char *file_name)
    {
        ifstream f(file_name);
        string l, t_id, t_name, t_match_id, t_win, t_loss;
        int x = 0;
        if (f.is_open())
        {
            while (getline(f, l))
            {
                x++;
            }
            m_num_of_matches = x - 1;
            tennis_matches = new TennisMatch[m_num_of_matches];
            f.clear();
            f.seekg(0);
            getline(f, l);
            
            for (size_t i = 0; i < m_num_of_matches; i++)
            {
                getline(f, t_id, ',');
                getline(f, t_name, ',');
                getline(f, t_match_id, ',');
                getline(f, t_win, ',');
                getline(f, t_loss);
                tennis_matches[i].t_match_id = stoi(t_match_id);
                tennis_matches[i].t_tournament_id = new char[t_id.length() + 1];
                tennis_matches[i].t_tournament_name = new char[t_name.length() + 1];
                tennis_matches[i].t_winner = new char[t_win.length() + 1];
                tennis_matches[i].t_loser = new char[t_loss.length() + 1];
                strcpy(tennis_matches[i].t_tournament_id, t_id.c_str());
                strcpy(tennis_matches[i].t_tournament_name, t_name.c_str());
                strcpy(tennis_matches[i].t_winner, t_win.c_str());
                strcpy(tennis_matches[i].t_loser, t_loss.c_str());
            }
            f.close();
        }
    }



    void TennisLog::addMatch(const TennisMatch &NewMatch)
    {
        if (tennis_matches != nullptr)
        {
            TennisMatch *T_log = new TennisMatch[m_num_of_matches + 1];
            for (size_t x = 0; x < m_num_of_matches; x++)
            {
                T_log[x] = tennis_matches[x];
            }
            T_log[m_num_of_matches] = NewMatch;
            delete[] tennis_matches;
            tennis_matches = T_log;
            m_num_of_matches++;
        }
        else
        {
            tennis_matches = new TennisMatch[1];
            tennis_matches[0] = NewMatch;
            m_num_of_matches = 1;
        }
    }
    TennisLog TennisLog::findMatches(const char *name_of_player) const
    {
        TennisLog T_log;
        for (size_t x = 0; x < m_num_of_matches; x++)
        {
            if (strcmp(tennis_matches[x].t_winner, name_of_player) == 0 || strcmp(tennis_matches[x].t_loser, name_of_player) == 0)
            {
                TennisMatch match(
                                  tennis_matches[x].t_tournament_id,
                                  tennis_matches[x].t_tournament_name,
                                  tennis_matches[x].t_match_id,
                                  tennis_matches[x].t_winner,
                                  tennis_matches[x].t_loser
                                  );
                T_log.addMatch(match);
            }
        }
        return T_log;
    }
}
