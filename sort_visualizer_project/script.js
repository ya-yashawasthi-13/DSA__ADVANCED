let array = [];

function generateArray(size = 50) {
  array = [];
  document.getElementById("array").innerHTML = '';
  for (let i = 0; i < size; i++) {
    let value = Math.floor(Math.random() * 300) + 10;
    array.push(value);
    const bar = document.createElement("div");
    bar.classList.add("bar");
    bar.style.height = `${value}px`;
    document.getElementById("array").appendChild(bar);
  }
}

function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

function updateBars() {
  const bars = document.getElementsByClassName("bar");
  for (let i = 0; i < array.length; i++) {
    bars[i].style.height = `${array[i]}px`;
  }
}

// ---------- Bubble Sort ----------
async function bubbleSort() {
  const bars = document.getElementsByClassName("bar");
  for (let i = 0; i < array.length - 1; i++) {
    for (let j = 0; j < array.length - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        [array[j], array[j + 1]] = [array[j + 1], array[j]];
        updateBars();
        await sleep(50);
      }
    }
  }
}

// ---------- Selection Sort ----------
async function selectionSort() {
  for (let i = 0; i < array.length; i++) {
    let minIdx = i;
    for (let j = i + 1; j < array.length; j++) {
      if (array[j] < array[minIdx]) {
        minIdx = j;
      }
    }
    if (minIdx !== i) {
      [array[i], array[minIdx]] = [array[minIdx], array[i]];
      updateBars();
      await sleep(50);
    }
  }
}

// ---------- Insertion Sort ----------
async function insertionSort() {
  for (let i = 1; i < array.length; i++) {
    let key = array[i];
    let j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
      updateBars();
      await sleep(50);
    }
    array[j + 1] = key;
    updateBars();
    await sleep(50);
  }
}

// ---------- Quick Sort ----------
async function quickSortVisualizer(start = 0, end = array.length - 1) {
  if (start >= end) return;

  let index = await partition(start, end);
  await Promise.all([
    quickSortVisualizer(start, index - 1),
    quickSortVisualizer(index + 1, end)
  ]);
}

async function partition(start, end) {
  const bars = document.getElementsByClassName("bar");
  let pivot = array[end];
  let i = start;

  for (let j = start; j < end; j++) {
    if (array[j] < pivot) {
      [array[i], array[j]] = [array[j], array[i]];
      updateBars();
      await sleep(50);
      i++;
    }
  }

  [array[i], array[end]] = [array[end], array[i]];
  updateBars();
  await sleep(50);

  return i;
}

// ---------- Merge Sort ----------
async function mergeSort(start = 0, end = array.length - 1) {
  if (start >= end) return;

  const mid = Math.floor((start + end) / 2);
  await mergeSort(start, mid);
  await mergeSort(mid + 1, end);
  await merge(start, mid, end);
}

async function merge(start, mid, end) {
  const bars = document.getElementsByClassName("bar");
  const left = array.slice(start, mid + 1);
  const right = array.slice(mid + 1, end + 1);

  let i = 0, j = 0, k = start;

  while (i < left.length && j < right.length) {
    if (left[i] <= right[j]) {
      array[k++] = left[i++];
    } else {
      array[k++] = right[j++];
    }
    updateBars();
    await sleep(50);
  }

  while (i < left.length) {
    array[k++] = left[i++];
    updateBars();
    await sleep(50);
  }

  while (j < right.length) {
    array[k++] = right[j++];
    updateBars();
    await sleep(50);
  }
}

// ---------- Heap Sort ----------
async function heapSort() {
  let n = array.length;

  for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
    await heapify(n, i);
  }

  for (let i = n - 1; i > 0; i--) {
    [array[0], array[i]] = [array[i], array[0]];
    updateBars();
    await sleep(50);
    await heapify(i, 0);
  }
}

async function heapify(n, i) {
  const bars = document.getElementsByClassName("bar");
  let largest = i;
  let l = 2 * i + 1;
  let r = 2 * i + 2;

  if (l < n && array[l] > array[largest]) largest = l;
  if (r < n && array[r] > array[largest]) largest = r;

  if (largest !== i) {
    [array[i], array[largest]] = [array[largest], array[i]];
    updateBars();
    await sleep(50);
    await heapify(n, largest);
  }
}

generateArray();
