#pragma once

// Standard Includes
#include <cstdint>

//------------------------------------------------------------------------------
/*
* This is a made up protocol that we will use to transfer files back and forth.
* Not related to the FTP protocol at all.
*
* A response must be immediatly after any command request.
* The file buffers are sent as fast as possible with no reply
*
* One limitation of the protocol is that the only way for the receiver of a file
* buffer to indicate error is to close the connection.
*
* Put command example:
*
* Client               Server
* -------Put Command-------->
* <--------Response----------
* --Transfer with CONTINUE-->
* --Transfer with CONTINUE-->
* ----Transfer with EOF----->
*
* 
*/
namespace MadeUpProtocol
{

const size_t MAXBUFFERSIZE = 1024;
const size_t MAXFILENAME   = 256;

const short  PORT_TRANSFER = 1026;

enum MessageType : uint8_t
{ 
    GET = 1
  , PUT
  , RESPONSE
  , TRANSFER_DATA
};

enum ErrorCode : uint8_t
{
    SUCCESS     = 0
  , BAD_COMMAND
  , FILE_EXISTS
  , FILE_NOT_EXISTS
  , FILE_ACCESS
  , FILE_CREATE
};

enum TRANSFER_FLAG : uint8_t
{
    ERROR = 99
  , CONTINUE
  , END_OF_FILE
};

/// <summary>
/// A GET or PUT Request
/// </summary>
struct CommandMessage
{
    uint8_t  m_type;
    uint8_t  m_pad;
    uint32_t m_namelength;
    char     m_filename[MAXFILENAME];
};

/// <summary>
/// Response to a Command Message
///
/// Just to demonstrate that we know about our bitwise operations and because it isn't uncommon for other protocols
/// to pack as much as they can into each byte, we'll include a bitfield byte
/// with the 
/// most significant  1 bit being a 1 if the time is PM and 0 for AM
/// least significant 3 bits will be the errorCode
/// </summary>
struct CommandResponse
{
    uint8_t m_type;
    uint8_t m_bitfield;

    bool GetPM() const;
    void SetPM(bool isPM);

    uint8_t GetErrorCode() const;
    void SetErrorCode(const uint8_t errorCode);
};

/// <summary>
/// Precedes file data
/// </summary>
struct TransferHeader
{
    uint8_t  m_type;
    uint8_t  m_flag;
    uint32_t m_dataLength;
};

}

