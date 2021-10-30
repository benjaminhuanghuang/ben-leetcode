/*
先将箱子按照单元数量从大到小排序。要想卡车装载单元数最大，那么需要尽量装单元数多的箱子。
所以排序以后从单元数量多的箱子开始取。一直取至 truckSize 没有空间。累积的单元数即最大总数。
*/
var maximumUnits = function (boxTypes, truckSize) {
  boxTypes.sort((box1, box2) => box2[1] - box1[1]);

  let totalUnits = 0;
  for (box of boxTypes) {
    if (truckSize >= box[0]) {
      truckSize -= box[0];
      totalUnits += box[1] * box[0];
    } else {
      totalUnits += truckSize * box[1];
      break;
    }
  }
  return totalUnits;
};
