package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
609. Find Duplicate File in System
Given a list of directory info including directory path, and all the files with contents in this directory,
you need to find out all the groups of duplicate files in the file system in terms of their paths.

A group of duplicate files consists of at least two files that have exactly the same content.

A single directory info string in the input list has the following format:

"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"

It means there are n files (f1.txt, f2.txt ... fn.txt with content f1_content, f2_content ... fn_content,
respectively) in directory root/d1/d2/.../dm. Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

The output is a list of group of duplicate file paths. For each group, it contains all the file paths of the files
that have the same content. A file path is a string that has the following format:

"directory_path/file_name.txt"
 */
public class LC_0609_FindDuplicateFileinSystem {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> map = new HashMap<>();

        for(String path : paths) {
            String[] pathArr = path.split(" ");
            String dir = pathArr[0] + '/';
            for (int i = 1; i < pathArr.length; i++) {
                int start = pathArr[i].indexOf('(');
                String fileName = dir + pathArr[i].substring(0, start);
                String content = pathArr[i].substring(start + 1, pathArr[i].length() - 1);
                map.putIfAbsent(content, new ArrayList<>());
                map.get(content).add(fileName);
            }
        }

        List<List<String>> res = new ArrayList<>();
        for (String key : map.keySet()) {
            if (map.get(key).size() > 1) {
                res.add(map.get(key));
            }
        }
        return res;
    }
}
