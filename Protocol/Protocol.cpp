

#include "Protocol.h"

namespace MadeUpProtocol
{

//------------------------------------------------------------------------------
bool CommandResponse::GetPM() const
{
    if( m_bitfield & 0x80 )
    {
        return true;
    }

    return false;
}

//------------------------------------------------------------------------------
void CommandResponse::SetPM(bool isPM)
{
    if( isPM )
    {
        m_bitfield |= 0x80;  // OR with 1000 0000
    }
    else
    {
        m_bitfield &= ~0x80; // AND with 0111 1111
    }
}

//------------------------------------------------------------------------------
uint8_t CommandResponse::GetErrorCode() const
{
    return m_bitfield & ~0x80; // AND with 0111 1111
}

//------------------------------------------------------------------------------
void CommandResponse::SetErrorCode(const uint8_t errorCode)
{
    m_bitfield |= (errorCode & ~0x80); // OR the original value with (errorCode AND with 0111 1111)
}

//------------------------------------------------------------------------------
} // End namespace

