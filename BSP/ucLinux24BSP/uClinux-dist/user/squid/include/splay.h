/*
 * $Id: splay.h,v 1.1.1.1 2006-07-11 09:33:06 andy Exp $
 */


typedef struct _splay_node {
    void *data;
    struct _splay_node *left;
    struct _splay_node *right;
} splayNode;

typedef int SPLAYCMP(const void *a, const void *b);
typedef void SPLAYWALKEE(void *nodedata, void *state);
typedef void SPLAYFREE(void *);

extern int splayLastResult;

extern splayNode *splay_insert(void *, splayNode *, SPLAYCMP *);
extern splayNode *splay_splay(const void *, splayNode *, SPLAYCMP *);
extern void splay_destroy(splayNode *, SPLAYFREE *);
extern void splay_walk(splayNode *, SPLAYWALKEE *, void *);
