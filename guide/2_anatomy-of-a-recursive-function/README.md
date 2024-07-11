# Anatomy of a Recursive Function

So far, you've been introduced to recursion as a general concept, and have had a bit of syntax practice with the general idea. It's now time to begin formalizing what makes something categorically recursive.

## Motivation

In order to get the most out of recursive functions, it helps to understand the structure that they take, and what purpose that structure confers.

## Anatomy

There are three main components to a recursive function:

* **Recursive calls:** your entry, and looping in recursion
* **Function logic:** what your function does, and the path it takes to evenually terminate
* **Base cases:** where and why your functions terminate

### Recursive Calls
A recursive call is simply a function call, wherever you want to continue your looping behavior. These are important to note as a category because, within a single call, you may choose to:

* 1 *or more* recursive calls within your logic
* Pass differing data to any of these calls
* Choose not to recurse at all, in your base case

Reading the above makes it sound like you need to decide where you go, based on certain conditions. That is exactly it though, you decide where to recurse and how, with conditionals.

Trivially, in our `sum.cpp` file, from the previous lesson, we had a single branch, a single conditional `if` statement. It's not overly exciting, but many simple recursive functions end up looking like this. If—instead—we have multiple branches, then we can change our recursive behavior. One of the simplest examplest examples of this, that is not contrived, is in searching a tree.

> Aside: if you are unfamiliar with binary trees, it's not crucial that you understand them entirely, but they are useful when discussing recursion. A binary tree is like a linked list, except that at each step, the path from the node forks into two directions (typically "left" and "right"). This has some handy properties, but for now just be aware that this is the kind of data structure "shape" you're dealing with. I only bring it up because recursion is uniquely equipped to deal with trees. Below is an image of a simple binary tree.\
![binary tree](./figures/binary_tree.png)


