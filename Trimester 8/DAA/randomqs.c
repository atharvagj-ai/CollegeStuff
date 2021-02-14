void do_qsort (void **ar, int(*cmp)(const void *,const void *),
               int left, int right) {
  int pivotIndex;
  if (right <= left) { return; }

  /* partition */
  pivotIndex = selectPivotIndex (ar, left, right);
  pivotIndex = partition (ar, cmp, left, right, pivotIndex);

  if (pivotIndex-1-left <= minSize) {
    insertion (ar, cmp, left, pivotIndex-1);
  } else {
    do_qsort (ar, cmp, left, pivotIndex-1);
  }
  if (right-pivotIndex-1 <= minSize) {
    insertion (ar, cmp, pivotIndex+1, right);
  } else {
    do_qsort (ar, cmp, pivotIndex+1, right);
  }
}

/**  Qsort straight */
void sortPointers (void **vals, int total_elems,
                   int(*cmp)(const void *,const void *)) {
  do_qsort (vals, cmp, 0, total_elems-1);
}