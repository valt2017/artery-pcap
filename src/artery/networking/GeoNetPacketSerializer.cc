#include "artery/networking/GeoNetPacket.h"
#include "artery/networking/GeoNetPacketSerializer.h"
#include <vanetza/geonet/serialization_buffer.hpp>
#include <vanetza/net/packet_variant.hpp>

Register_Class(artery::GeoNetPacketSerializer)
// protocol set to unknown, lookup using classname will be used in inet serializer
Register_Serializer(artery::GeoNetPacket, inet::serializer::UNKNOWN, inet::serializer::UNKNOWN, artery::GeoNetPacketSerializer);

namespace artery
{

void GeoNetPacketSerializer::serialize(const cPacket *pkt, inet::serializer::Buffer &b, inet::serializer::Context& context)
{
    const artery::GeoNetPacket *geoNetPacket = static_cast<const artery::GeoNetPacket *>(pkt);
    auto view = boost::create_byte_view(geoNetPacket->getPayload(), vanetza::OsiLayer::Network, vanetza::OsiLayer::Application);
    vanetza::ByteBuffer buff(view.begin(), view.end());
    
    for(size_t i = 0; i < buff.size(); i++){
        b.writeByte(buff[i]);
    }
}

cPacket* GeoNetPacketSerializer::deserialize(const inet::serializer::Buffer &b, inet::serializer::Context& context)
{
    return nullptr;
}

} // namespace artery
