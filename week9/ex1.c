#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct Page {
    unsigned char lifespan;
    int referenced;
    unsigned int pageNumber;
} Page;

typedef struct PageTable {
    Page **pages;
    int count;
} PageTable;

Page *initPage(unsigned int pageNumber) {
    Page *p = malloc(sizeof(Page));
    p->referenced = 0;
    p->lifespan = 0;
    p->pageNumber = pageNumber;
    return p;
}

PageTable *initPageTable(int size) {
    PageTable *pt = malloc(sizeof(PageTable));
    pt->pages = malloc(size * sizeof(Page *));
    pt->count = 0;
    return pt;
}

void updateTable(PageTable *pt) {
    unsigned char bitMask = 0;
    for (int i = 0; i < pt->count; ++i) {
        if (pt->pages[i]->referenced) {
            bitMask = 1 << (sizeof(unsigned char) - 1);
        } else {
            bitMask = 0;
        }
        pt->pages[i]->lifespan = (pt->pages[i]->lifespan >> 1) | bitMask;
        pt->pages[i]->referenced = 0;
    }
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    unsigned int cur_frame;
    int found = 0;
    int hit = 0;
    int miss = 0;
    unsigned int pageToReplace = 0;
    unsigned char pageToReplaceSpan = UCHAR_MAX;
    PageTable *pageTable = initPageTable(n);
    FILE *file = fopen("input.txt", "r");
    printf("Hits:\n");
    while (fscanf(file, "%d", &cur_frame) == 1) {
        found = 0;
        pageToReplaceSpan = UCHAR_MAX;
        for (int i = 0; i < pageTable->count; ++i) {
            if (pageTable->pages[i]->pageNumber == cur_frame) {
                pageTable->pages[i]->referenced = 1;
                found = 1;
                printf("%d ", cur_frame);
                ++hit;
                break;
            }
        }
        if (found != 1) {
            if (pageTable->count < n) {
                pageTable->pages[pageTable->count] = initPage(cur_frame);
                pageTable->pages[pageTable->count]->referenced = 1;
                pageTable->count++;
            } else {
                for (int i = 0; i < pageTable->count; ++i) {
                    if (pageTable->pages[i]->lifespan < pageToReplaceSpan) {
                        pageToReplaceSpan = pageTable->pages[i]->lifespan;
                        pageToReplace = i;
                    }
                }
                pageTable->pages[pageToReplace]->lifespan = 0;
                pageTable->pages[pageToReplace]->referenced = 1;
                pageTable->pages[pageToReplace]->pageNumber = cur_frame;
            }
            ++miss;
        }
        updateTable(pageTable);
    }
    fclose(file);

    printf("\nHit/Miss (%d/%d) rate: %f%%\n", hit, miss, ((double) hit / miss) * 100);

    return 0;
}
