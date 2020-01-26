import os
from shutil import copyfile

CPP_SOLUTIONS_FOLDER = "/Users/bhuang/ben-github/cpp-interview/leetcode/"

PY_SOLUTIONS_FOLDER = "/Users/bhuang/ben-github/pyinterview/leet_code/"

TARGET_PATH = "/Users/bhuang/ben-github/ben-leetcode/"

def copyCppSolutions():
  sourceFiles = [x for x in os.listdir(CPP_SOLUTIONS_FOLDER) if x.endswith(".cpp")]
  for f in sourceFiles:
    solutionNum = f.split('.')[0]

    cppFilePath = os.path.join(CPP_SOLUTIONS_FOLDER, f) 

    targetFolder = getTargetFolder(solutionNum)
    if targetFolder:
      targetFiePath = os.path.join(targetFolder, "solution.cpp")
      print("Copy {} to {}".format(cppFilePath, targetFiePath))
      copyfile(cppFilePath, targetFiePath)

def copyPythonSolutions():
  sourceFiles = [x for x in os.listdir(PY_SOLUTIONS_FOLDER) if x.endswith(".py")]
  for f in sourceFiles:
    solutionNum = '0'+ f.split('_')[0]

    cppFilePath = os.path.join(PY_SOLUTIONS_FOLDER, f) 

    targetFolder = getTargetFolder(solutionNum)
    if targetFolder:
      targetFiePath = os.path.join(targetFolder, "solution.py")
      print("Copy {} to {}".format(cppFilePath, targetFiePath))
      copyfile(cppFilePath, targetFiePath)


def getTargetFolder(solutionNum):
  subfolders = [ e.path for e in os.scandir(TARGET_PATH) if e.is_dir() and e.name.startswith(solutionNum)]
  if len(subfolders) > 0:
    return subfolders[0]
  return None

if __name__ == "__main__":
  # copyCppSolutions()
  copyPythonSolutions()