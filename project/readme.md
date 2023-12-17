# Project Overview

**The purpose of this project is to put C++ Object Oriented skills to practice by developing a simulation of an assembly line with any number of stations. A line with 3 Stations is illustrated in the figure below.**

![image](https://github.com/emyildirim/BTP305/assets/105301175/7110e3f9-ac52-4605-86f2-05a358464f39)

The assembly line in the solution consists of a set of workstations each of which holds a set of stock items, which are specific to the station. A line manager moves customer orders along the line filling the orders at each station, as requested. Each customer order consists of a list of items that need to be filled. Each station processes a queue of orders by filling the next order in the queue if that order requests the station's item and that item is in stock. The line manager keeps moving the customer orders from station to station until all orders have been processed. Any station that has used all the items in stock cannot fill any more orders. At the end of the line orders are either completed or incomplete due to a lack of inventory at one or more stations. The simulator lists the completed orders and those that are incomplete once the line manager has finished processing all orders.

The project is divided into 3 milestones to show you through implementation, debugging and execution due to its complexity.