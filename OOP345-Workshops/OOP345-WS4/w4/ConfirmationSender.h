

#ifndef SDDS_CONFIRMATION_SENDER_H
#define SDDS_CONFIRMATION_SENDER_H

#include "Reservation.h"

namespace sdds
{
    class ConfirmationSender
    {
        const Reservation **m_pReservations{nullptr};
        size_t m_elements{0u};

    public:
        ConfirmationSender();
        ConfirmationSender(const ConfirmationSender &res_obj);
        ConfirmationSender &operator=(const ConfirmationSender &res_obj);
        ConfirmationSender(ConfirmationSender &&res_obj);
        ConfirmationSender &operator=(ConfirmationSender &&res_obj);
        ConfirmationSender &operator+=(const Reservation &res_obj);
        ConfirmationSender &operator-=(const Reservation &res_obj);
        ~ConfirmationSender();
        friend std::ostream &operator<<(std::ostream &ostr, const ConfirmationSender &src);
    };
}
#endif // !SDDS_CONFIRMATION_SENDER_H

