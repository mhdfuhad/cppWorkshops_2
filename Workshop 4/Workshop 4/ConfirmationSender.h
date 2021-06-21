//
//  ConfirmationSender.h
//  Workshop 4
//
//  Created by Mohammad Fuhad Uddin on 2021-06-21.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_ConfirmationSender_h
#define SDDS_ConfirmationSender_h

#include "Reservation.h"

namespace sdds{

class ConfirmationSender{
    const Reservation** m_Confirmations{nullptr};
    size_t count = {0};
public:
    ConfirmationSender();
    ConfirmationSender(const ConfirmationSender& obj);
    ConfirmationSender& operator=(const ConfirmationSender& obj);
    ConfirmationSender(ConfirmationSender&& obj) noexcept;
    ConfirmationSender& operator=(ConfirmationSender&& obj) noexcept;
    ~ConfirmationSender();
    ConfirmationSender& operator+=(const Reservation& res);
    ConfirmationSender& operator-=(const Reservation& res);
    friend std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender& obj);
};

}

#endif /* SDDS_ConfirmationSender_h */
