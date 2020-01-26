import os
from shutil import copyfile

CPP_SOLUTIONS_FOLDER = "/Users/bhuang/ben-github/cpp-interview/leetcode/"

TARGET_PATH = "/Users/bhuang/ben-github/ben-leetcode/"

def copyCppSolutions():
  cppFiles = [x for x in os.listdir(CPP_SOLUTIONS_FOLDER) if x.endswith(".cpp")]
  for f in cppFiles:
    solutionNum = f.split('.')[0]

    cppFilePath = os.path.join(CPP_SOLUTIONS_FOLDER, f) 

    targetFolder = getTargetFolder(solutionNum)

    targetFiePath = os.path.join(targetFolder, "solution.cpp")
    print("Copy {} to {}".format(cppFilePath, targetFiePath))
    


def getTargetFolder(solutionNum):
  print(solutionNum)
  subfolders = [ e.path for e in os.scandir(TARGET_PATH) if e.is_dir() and e.name.startswith(solutionNum)]
  return subfolders[0]

if __name__ == "__main__":
  copyCppSolutions()