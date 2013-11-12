#include "Hect.h"

using namespace hect;

MeshJsonFormat::MeshJsonFormat()
{
    _indexTypes["Unsigned8"] = Mesh::Unsigned8;
    _indexTypes["Unsigned16"] = Mesh::Unsigned16;
    _indexTypes["Unsigned32"] = Mesh::Unsigned32;

    _primitiveTypes["Triangles"] = Mesh::Triangles;
    _primitiveTypes["TriangleStrip"] = Mesh::TriangleStrip;
    _primitiveTypes["Lines"] = Mesh::Lines;
    _primitiveTypes["LineStrip"] = Mesh::LineStrip;
    _primitiveTypes["Points"] = Mesh::Points;

    _attributeSemantics["Position"] = VertexAttribute::Position;
    _attributeSemantics["Normal"] = VertexAttribute::Normal;
    _attributeSemantics["Color"] = VertexAttribute::Color;
    _attributeSemantics["Tangent"] = VertexAttribute::Tangent;
    _attributeSemantics["Binormal"] = VertexAttribute::Binormal;
    _attributeSemantics["Weight0"] = VertexAttribute::Weight0;
    _attributeSemantics["Weight1"] = VertexAttribute::Weight1;
    _attributeSemantics["Weight2"] = VertexAttribute::Weight2;
    _attributeSemantics["Weight3"] = VertexAttribute::Weight3;
    _attributeSemantics["TextureCoords0"] = VertexAttribute::TextureCoords0;
    _attributeSemantics["TextureCoords1"] = VertexAttribute::TextureCoords1;
    _attributeSemantics["TextureCoords2"] = VertexAttribute::TextureCoords2;
    _attributeSemantics["TextureCoords3"] = VertexAttribute::TextureCoords3;

    _attributeTypes["Float16"] = VertexAttribute::Float16;
    _attributeTypes["Float32"] = VertexAttribute::Float32;
}

void MeshJsonFormat::load(Mesh& mesh, ReadStream& stream)
{
    DataValue root = JsonParser().parse(stream);

    // Index type (optional)
    if (root["indexType"].isString())
    {
        Mesh::IndexType indexType = _parseIndexType(root["indexType"].asString());
        mesh.setIndexType(indexType);
    }

    // Primitive type (optional)
    if (root["primitiveType"].isString())
    {
        Mesh::PrimitiveType primitiveType = _parsePrimitiveType(root["primitiveType"].asString());
        mesh.setPrimitiveType(primitiveType);
    }

    // Vertex layout (optional)
    if (root["vertexLayout"].isArray())
    {
        VertexAttribute::Array attributes;
        for (const DataValue& attribute : root["vertexLayout"])
        {
            auto semantic =_parseAttributeSemantic(attribute["semantic"].asString());
            auto type = _parseAttributeType(attribute["type"].asString());
            auto cardinality = attribute["cardinality"].asUnsigned();

            attributes.push_back(VertexAttribute(semantic, type, cardinality));
        }
        mesh.setVertexLayout(VertexLayout(attributes));
    }

    MeshBuilder meshBuilder(mesh);

    // Add the vertices
    for (const DataValue& vertex : root["vertices"])
    {
        meshBuilder.addVertex();

        // For each attribute
        for (const DataValue& attribute : vertex)
        {
            auto semantic = _parseAttributeSemantic(attribute["semantic"].asString());

            switch (semantic)
            {
            case VertexAttribute::Position:
            case VertexAttribute::Normal:
            case VertexAttribute::Tangent:
            case VertexAttribute::Binormal:
                meshBuilder.setAttributeData(semantic, parseVector3(attribute["data"]));
                break;
            default:
                meshBuilder.setAttributeData(semantic, parseVector2(attribute["data"]));
            }
        }
    }

    // Add the indices
    for (const DataValue& index : root["indices"])
    {
        unsigned indexValue = index.asUnsigned();
        meshBuilder.addIndex(indexValue);
    }
}

Mesh::IndexType MeshJsonFormat::_parseIndexType(const DataValue& dataValue)
{
    auto it = _indexTypes.find(dataValue.asString());
    if (it == _indexTypes.end())
    {
        throw Error(format("Invalid index type '%s'", dataValue.asString().c_str()));
    }

    return (*it).second;
}

Mesh::PrimitiveType MeshJsonFormat::_parsePrimitiveType(const DataValue& dataValue)
{
    auto it = _primitiveTypes.find(dataValue.asString());
    if (it == _primitiveTypes.end())
    {
        throw Error(format("Invalid primitive type '%s'", dataValue.asString().c_str()));
    }

    return (*it).second;
}

VertexAttribute::Semantic MeshJsonFormat::_parseAttributeSemantic(const DataValue& dataValue)
{
    auto it = _attributeSemantics.find(dataValue.asString());
    if (it == _attributeSemantics.end())
    {
        throw Error(format("Invalid vertex attribute semantic '%s'", dataValue.asString().c_str()));
    }

    return (*it).second;
}

VertexAttribute::Type MeshJsonFormat::_parseAttributeType(const DataValue& dataValue)
{
    auto it = _attributeTypes.find(dataValue.asString());
    if (it == _attributeTypes.end())
    {
        throw Error(format("Invalid vertex attribute type '%s'", dataValue.asString().c_str()));
    }

    return (*it).second;
}