// Copyright 2018 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _TCP_CHANNEL_RESOURCE_BASIC_
#define _TCP_CHANNEL_RESOURCE_BASIC_

#include <asio.hpp>
#include <fastrtps/transport/TCPChannelResource.h>

namespace eprosima{
namespace fastrtps{
namespace rtps{

class TCPChannelResourceBasic : public TCPChannelResource
{
    asio::io_service& service_;
    asio::ip::tcp::socket* socket_;
public:
    // Constructor called when trying to connect to a remote server
    TCPChannelResourceBasic(
        TCPTransportInterface* parent,
        RTCPMessageManager* rtcpManager,
        asio::io_service& service,
        const Locator_t& locator,
        uint32_t maxMsgSize);

    // Constructor called when local server accepted connection
    TCPChannelResourceBasic(
        TCPTransportInterface* parent,
        RTCPMessageManager* rtcpManager,
        asio::io_service& service,
        asio::ip::tcp::socket* socket,
        uint32_t maxMsgSize);

    virtual ~TCPChannelResourceBasic();

    void connect() override;

    void disconnect() override;

    uint32_t read(
        octet* buffer,
        std::size_t size,
        asio::error_code& ec) override;

    uint32_t send(
        const octet* data,
        size_t size,
        asio::error_code& ec) override;

    asio::ip::tcp::endpoint remote_endpoint() const override;
    asio::ip::tcp::endpoint local_endpoint() const override;

    void set_options(const TCPTransportDescriptor* options) override;

    void cancel() override;
    void close() override;
    void shutdown(asio::socket_base::shutdown_type what) override;

    inline asio::ip::tcp::socket* socket()
    {
        return socket_;
    }

private:
    TCPChannelResourceBasic(const TCPChannelResourceBasic&) = delete;
    TCPChannelResourceBasic& operator=(const TCPChannelResourceBasic&) = delete;
};


} // namespace rtps
} // namespace fastrtps
} // namespace eprosima

#endif // _TCP_CHANNEL_RESOURCE_BASIC_