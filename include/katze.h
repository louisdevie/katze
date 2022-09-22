#pragma once

#include <stddef.h>

#define KATZE_VERSION "0.0.1"
#define KATZE_VERSION_MAJOR 0
#define KATZE_VERSION_MINOR 0
#define KATZE_VERSION_PATCH 1

enum NodeType
{
    NODE_PARAGRAPH,
    NODE_TITLE,
    NODE_HEADING_1,
    NODE_HEADING_2,
    NODE_HEADING_3,
    NODE_HEADING_4,
    NODE_HEADING_5,
    NODE_HEADING_6,
    NODE_LIST_UNORDERED,
    NODE_LIST_ORDERED,
    NODE_LIST_MARKER,
    NODE_LIST_ITEM,
    NODE_CODE,
    NODE_ITALIC,
    NODE_BOLD,
    NODE_UNDERLINE,
    NODE_STRIKETHROUGH,
    NODE_HIGHLIGHT,
    NODE_SUPERSCRIPT,
    NODE_SUBSCRIPT,
    NODE_FOOTNOTE,
};

struct Node
{
    struct Node *next_sibling;
    struct Node *first_child;
    enum NodeType type;
    size_t start;
    size_t span;
};

struct Document
{
    struct Node *first_child;
};

#ifdef __cplusplus
extern "C"
{
#endif

    void parse_document(char *text, size_t length, enum Encoding format,
                        struct Document *doc);

#ifdef __cplusplus
}
#endif