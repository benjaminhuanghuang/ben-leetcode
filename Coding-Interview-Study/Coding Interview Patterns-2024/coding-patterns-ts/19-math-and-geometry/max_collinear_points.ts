function maximum_collinear_points(points: [number, number][]): number {
  if (points.length < 3) {
    return points.length;
  }
  let maxPoints = 1;

  for (let i = 0; i < points.length; i++) {
    const slopes = new Map<string, number>();
    let duplicatePoints = 0;
    let currentMax = 0;
    for (let j = 0; j < points.length; j++) {
      if (i === j) continue;
      const deltaX = points[j][0] - points[i][0];
      const deltaY = points[j][1] - points[i][1];
      if (deltaX === 0 && deltaY === 0) {
        duplicatePoints++;
        continue;
      }
      const gcdValue = gcd(Math.abs(deltaX), Math.abs(deltaY));
      const slopeX = deltaX / gcdValue;
      const slopeY = deltaY / gcdValue;
      const slopeKey = `${slopeY}/${slopeX}`;
      slopes.set(slopeKey, (slopes.get(slopeKey) || 0) + 1);
      currentMax = Math.max(currentMax, slopes.get(slopeKey)!);
    }
    maxPoints = Math.max(maxPoints, currentMax + duplicatePoints + 1);
  }

  return maxPoints;
}
