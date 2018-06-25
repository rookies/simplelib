#pragma once

#include <cstddef>
#include "FormattedOutput.hh"

/**
 * Formats data and outputs it into a buffer.
 */
class FormattedOutputBuffer : public FormattedOutput {
public:
    /**
     * Initializes the class with the given buffer.
     *
     * @param buf the buffer to use
     * @param len the length of the buffer
     */
    FormattedOutputBuffer(char *buf, size_t len);

    /**
     * Sets a new buffer to output to.
     *
     * @param buf the buffer to use
     * @param len the length of the buffer
     */
    void setBuffer(char *buf, size_t len);

    int printChar(char c) override;
private:
    /**
     * The buffer used to output.
     */
    char *m_buf;

    /**
     * The length of the buffer.
     */
    size_t m_len;

    /**
     * The current position in the buffer.
     */
    size_t m_pos;
};