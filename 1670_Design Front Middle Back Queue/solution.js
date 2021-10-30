var FrontMiddleBackQueue = function() {
    
};

/** 
 * @param {number} val
 * @return {void}
 */
FrontMiddleBackQueue.prototype.pushFront = function(val) {
    
};

/** 
 * @param {number} val
 * @return {void}
 */
FrontMiddleBackQueue.prototype.pushMiddle = function(val) {
    
};

/** 
 * @param {number} val
 * @return {void}
 */
FrontMiddleBackQueue.prototype.pushBack = function(val) {
    
};

/**
 * @return {number}
 */
FrontMiddleBackQueue.prototype.popFront = function() {
    
};

/**
 * @return {number}
 */
FrontMiddleBackQueue.prototype.popMiddle = function() {
    
};

/**
 * @return {number}
 */
FrontMiddleBackQueue.prototype.popBack = function() {
    
};

/** 
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * var obj = new FrontMiddleBackQueue()
 * obj.pushFront(val)
 * obj.pushMiddle(val)
 * obj.pushBack(val)
 * var param_4 = obj.popFront()
 * var param_5 = obj.popMiddle()
 * var param_6 = obj.popBack()
 */

 class FrontMiddleBackQueue {
    constructor() {
      this.items = [];
    }
    
    pushFront(val) {
      this.items.unshift(val);
    }
    
    pushMiddle(val) {
      const middleIndex = Math.floor(this.items.length / 2);
      this.items.splice(middleIndex, 0, val);
    }
    
    pushBack(val) {
      this.items.push(val);
    }
    
    popFront() {
      if (!this.items.length) return -1;
      return this.items.shift();
    }
    
    popMiddle() {
      if (!this.items.length) return -1;
      const middleIndex = Math.floor(this.items.length / 2) - (1 - (this.items.length & 1));
      return this.items.splice(middleIndex, 1)[0];
    }
    
    popBack() {
      if (!this.items.length) return -1;
      return this.items.pop();
    }
  }