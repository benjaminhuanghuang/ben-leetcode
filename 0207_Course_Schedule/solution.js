/*
207. Course Schedule
*/
/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function(numCourses, prerequisites) {
  var map = {}, visited = {}, visitedPath = {};
  //build map
  for(i = 0; i < numCourses; i++){
      map[i] = { index : i, next : [] };
  }
  //add edge
  for(i = 0; i < prerequisites.length; i++){
      map[prerequisites[i][1]].next.push(map[prerequisites[i][0]]);
  }
  //bfs
  for(i = 0; i < numCourses; i++){
      if(!visited[i]){
          if(!bfs(map[i])){
              return false;
          }    
      }        
  }
  return true;

  function bfs(node){
      visited[node.index] = true;
      visitedPath[node.index] = true;
      if(node.next.length > 0){
          for(var i = 0; i < node.next.length; i++){
              if(visitedPath[node.next[i].index]){
                  return false;
              } 
              if(!bfs(map[node.next[i].index])){
                  return false;
              }
          }
      }
      visitedPath[node.index] = false;
      return true;
  }
};