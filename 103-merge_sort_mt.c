#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_THREADS 16
#define MIN_BLOCK_SIZE 64

typedef struct {
    int *arr;
    int l;
    int r;
} merge_sort_params;

void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void *merge_sort(void *params) {
    merge_sort_params *p = (merge_sort_params *) params;
    int *arr = p->arr;
    int l = p->l;
    int r = p->r;
    int m;
    pthread_t tid1, tid2;
    merge_sort_params p1, p2;
    if (r > l) {
        m = l + (r - l) / 2;
        p1.arr = arr;
        p1.l = l;
        p1.r = m;
        pthread_create(&tid1, NULL, merge_sort, &p1);
        p2.arr = arr;
        p2.l = m + 1;
        p2.r = r;
        pthread_create(&tid2, NULL, merge_sort, &p2);
        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);
        merge(arr, l, m, r);
    }
    pthread_exit(0);
}



/*
 * Apparently, this version works without owning `main.`
 * remains to be seen.
 */
/* static inline void *tiled_merge_sort_thread(void *params) { */
/*     tiled_merge_sort_params *p = (tiled_merge_sort_params *) params; */
/*     int *arr = p->arr; */
/*     int l = p->l; */
/*     int r = p->r; */
/*     int m; */
/*     pthread_t tid1, tid2; */
/*     tiled_merge_sort_params p1, p2; */
/*     if (r - l + 1 <= S) { */
/*         insertion_sort(arr + l, r - l + 1); */
/*     } else { */
/*         m = l + (r - l) / 2; */
/*         p1.arr = arr; */
/*         p1.l = l; */
/*         p1.r = m; */
/*         pthread_create(&tid1, NULL, tiled_merge_sort_thread, &p1); */
/*         p2.arr = arr; */
/*         p2.l = m + 1; */
/*         p2.r = r; */
/*         pthread_create(&tid2, NULL, tiled_merge_sort_thread, &p2); */
/*         pthread_join(tid1, NULL); */
/*         pthread_join(tid2, NULL); */
/*         merge(arr, l, m, r); */
/*     } */
/*     pthread_exit(0); */
/* } */
/* When invoked, this will call `tiled_merge_sort_thread` */
/* pthread_create(&tid, NULL, tiled_merge_sort_thread, &params); */
