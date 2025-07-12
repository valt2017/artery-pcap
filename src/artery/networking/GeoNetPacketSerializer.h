#ifndef ARTERY_GEONETPACKETSERIALIZER_H_OT36RUH0
#define ARTERY_GEONETPACKETSERIALIZER_H_OT36RUH0

#include <vanetza/net/packet_variant.hpp>
#include <omnetpp/cpacket.h>
#include <inet/common/serializer/headers/defs.h>
#include <inet/common/serializer/SerializerBase.h>

namespace artery
{

class GeoNetPacketSerializer : public inet::serializer::SerializerBase {
  protected:
    virtual void serialize(const cPacket *pkt, inet::serializer::Buffer &b, inet::serializer::Context& context) override;
    virtual cPacket* deserialize(const inet::serializer::Buffer &b, inet::serializer::Context& context) override;

  public:
    GeoNetPacketSerializer(const char *name = nullptr) : inet::serializer::SerializerBase(name) {}
};

} // namespace artery

#endif /* ARTERY_GEONETPACKETSERIALIZER_H_OT36RUH0 */

