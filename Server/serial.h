#ifndef SERIAL_H
#define SERIAL_H


class Serial
{
public:
    virtual unsigned char transfer (unsigned char data) =0;
};

#endif // SERIAL_H
