

#include "ConfirmationSender.h"
using namespace std;
namespace sdds
{
    ConfirmationSender::ConfirmationSender() {}
    ConfirmationSender::ConfirmationSender(const ConfirmationSender &res_obj)
    {
        m_pReservations = nullptr;
        *this = res_obj;
    }
    ConfirmationSender &ConfirmationSender::operator=(const ConfirmationSender &res_obj)
    {
        if (this != &res_obj)
        {
            m_elements = res_obj.m_elements;
            delete[] m_pReservations;
            if (res_obj.m_pReservations != nullptr)
            {
                m_pReservations = new const Reservation *[m_elements];
                for (size_t i = 0; i < m_elements; i++)
                    m_pReservations[i] = res_obj.m_pReservations[i];
            }
            else
            {
                m_pReservations = nullptr;
            }
        }
        return *this;
    }
    ConfirmationSender::ConfirmationSender(ConfirmationSender &&res_obj)
    {
        *this = move(res_obj);
    }
    ConfirmationSender &ConfirmationSender::operator=(ConfirmationSender &&res_obj)
    {
        if (this != &res_obj)
        {
            delete[] m_pReservations;
            m_pReservations = res_obj.m_pReservations;
            m_elements = res_obj.m_elements;
            res_obj.m_pReservations = nullptr;
            res_obj.m_elements = 0u;
        }
        return *this;
    }
    ConfirmationSender::~ConfirmationSender()
    {
        delete[] m_pReservations;
    }
    ConfirmationSender &ConfirmationSender::operator+=(const Reservation &res_obj)
    {
        bool ifRes = false;
        for (size_t i = 0; i < m_elements; i++)
        {
            if (m_pReservations[i] == &res_obj)
            {
                ifRes = true;
            }
        }
        if (!ifRes)
        {
            const Reservation **ppTempRes = nullptr;
            ppTempRes = new const Reservation *[m_elements + 1];
            for (size_t i = 0; i < m_elements; i++)
            {
                ppTempRes[i] = m_pReservations[i];
            }
            ppTempRes[m_elements] = &res_obj;
            m_elements++;
            delete[] m_pReservations;
            m_pReservations = ppTempRes;
        }
        return *this;
    }
    ConfirmationSender &ConfirmationSender::operator-=(const Reservation &res_obj)
    {
        bool flag{false};
        size_t k{0};
        for (size_t i = 0; i < m_elements && !flag; ++i)
        {
            if (m_pReservations[i] == &res_obj)
            {
                flag = true;
                k = i;
            }
        }
        if (flag)
        {
            const Reservation **res_obj{nullptr};
            res_obj = new const Reservation *[m_elements - 1];
            for (size_t j = 0, i = 0; j < m_elements; j++, i++)
            {
                if (k != j)
                {
                    res_obj[i] = m_pReservations[j];
                }
                else
                {
                    i--;
                }
            }
            m_elements--;
            delete[] m_pReservations;
            m_pReservations = res_obj;
        }
        return *this;
    }
    ostream &operator<<(ostream &os, const ConfirmationSender &src)
    {
        os.fill('-');
        os.width(26);
        os << "-";
        os.fill(' ');
        os << "\nConfirmations to Send\n";
        os.fill('-');
        os.width(26);
        os << "-";
        os.fill(' ');
        os << endl;
        if (src.m_elements > 0)
        {
            for (size_t i = 0; i < src.m_elements; i++)
                os << *src.m_pReservations[i];
        }
        else
        {
            os << "There are no confirmations to send!" << endl;
        }
        os.fill('-');
        os.width(26);
        os << "-";
        os.fill(' ');
        os << endl;
        return os;
    }
}

