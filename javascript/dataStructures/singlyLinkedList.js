// insert(index, value) {
//   if (index < 0 || index > this.length) return false;
//   if (index === 0) return !!this.unshift(value);
//   if (index === this.length) return !!this.push(value);

//   const newNode = new Node(value);
//   const prev = this.get(index - 1);

//   newNode.next = prev.next;
//   prev.next = newNode;

//   this.length++;
//   return true;
// }

// Implement the following methods
/*
push, pop, shift, unshift, get, set, insert, remove, reverse, rotate
*/