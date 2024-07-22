

#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H

#include <iostream>

namespace sdds
{
    struct TennisMatch
    {
        int t_match_id;
        char *t_winner;
        char *t_loser;
        char *t_tournament_name;
        char *t_tournament_id;
        TennisMatch();
        TennisMatch(const char *tournamentID, const char *tournamentName, int matchID, const char *matchWinner, const char *matchLoser);
        friend std::ostream &operator<<(std::ostream &out, const TennisMatch &m);
    };
    class TennisLog
    {
        TennisMatch *tennis_matches;
        size_t m_num_of_matches;

    public:
        TennisLog();
        TennisLog(const TennisLog &Tlog);
        TennisLog& operator=(const TennisLog& Tlog);
        TennisLog(TennisLog&& Tlog);
        TennisLog& operator=(TennisLog&& Tlog);
        ~TennisLog();
        operator size_t() const;
        TennisMatch operator[](size_t i);
        TennisLog(const char *file_name);
        void addMatch(const TennisMatch &NewMatch);
        TennisLog findMatches(const char *name_of_player) const;
    };
}
#endif
