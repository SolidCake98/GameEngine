#pragma once

class VertexBuffer
{
private:
	unsigned int m_RendererID;

public:
	VertexBuffer(const void*, unsigned int);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;

};

