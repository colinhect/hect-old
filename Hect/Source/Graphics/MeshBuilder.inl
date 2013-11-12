namespace hect
{

template <typename T>
void MeshBuilder::_setAttributeData(const VertexAttribute& attribute, const T& value)
{
    T* data = (T*)&_mesh->_vertexData[_vertexDataIndex + attribute.offset()];
    *data = value;
}

}