#include "FormattedOutputBuffer.hh"

FormattedOutputBuffer::FormattedOutputBuffer(char *buf, size_t len) :
        m_buf{buf}, m_len{len}, m_pos{0} {

}

void FormattedOutputBuffer::setBuffer(char *buf, size_t len) {
    m_buf = buf;
    m_len = len;
    m_pos = 0;
}

int FormattedOutputBuffer::printChar(char c) {
    if (m_pos >= m_len) return -1;
    m_buf[m_pos++] = c;
    return 0;
}