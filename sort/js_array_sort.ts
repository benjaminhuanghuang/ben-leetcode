function sort() {
  const unsortedArray = Array.from({ length: 1000 }, () =>
    Math.floor(Math.random() * 1000)
  );

  const sortedArray = [...unsortedArray].sort((a, b) => a - b);
}
