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

#include <fastrtps/transport/TCPAcceptor.h>
#include <fastrtps/transport/TCPTransportInterface.h>
#include <fastrtps/utils/IPLocator.h>

namespace eprosima{
namespace fastrtps{
namespace rtps{

TCPAcceptor::TCPAcceptor(
    asio::io_service& io_service,
    TCPTransportInterface* parent,
    const Locator_t& locator)
    : acceptor(io_service, parent->GenerateEndpoint(IPLocator::getPhysicalPort(locator)))
    , locator(locator)
{
    endpoint = asio::ip::tcp::endpoint(parent->GenerateProtocol(), IPLocator::getPhysicalPort(locator));
}

TCPAcceptor::TCPAcceptor(
    asio::io_service& io_service,
    const std::string& interface,
    const Locator_t& locator)
    : acceptor(io_service, asio::ip::tcp::endpoint(asio::ip::address_v4::from_string(interface),
        IPLocator::getPhysicalPort(locator)))
    , locator(locator)
{
    endpoint = asio::ip::tcp::endpoint(asio::ip::address_v4::from_string(interface),
        IPLocator::getPhysicalPort(locator));
}

} // namespace rtps
} // namespace fastrtps
} // namespace eprosima
