void* memset(void *dst, int value, unsigned int size) {
    unsigned char *ptr = (unsigned char *)dst;
    unsigned char byte_value = (unsigned char)value;

    // Fill memory byte by byte
    while (size > 0) {
        *ptr = byte_value;
        ptr++;
        size--;
    }

    return dst;  // Return original pointer as per standard
}

void* memcpy(void *dst, const void *src, unsigned int size) {
    unsigned char *dest_ptr = (unsigned char *)dst;
    const unsigned char *src_ptr = (const unsigned char *)src;

    while (size > 0) {
        *dest_ptr = *src_ptr;
        dest_ptr++;
        src_ptr++;
        size--;
    }

    return dst;
}
