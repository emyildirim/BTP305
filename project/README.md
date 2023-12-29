# Project Overview

**The purpose of this project is to put C++ Object Oriented skills to practice by developing a simulation of an assembly line with any number of stations. A line with 3 Stations is illustrated in the figure below.**

   ![assemblyline demo](assemblyline.jpg)

The assembly line in the solution consists of a set of workstations each of which holds a set of stock items, which are specific to the station. A line manager moves customer orders along the line filling the orders at each station, as requested. Each customer order consists of a list of items that need to be filled. Each station processes a queue of orders by filling the next order in the queue if that order requests the station's item and that item is in stock. The line manager keeps moving the customer orders from station to station until all orders have been processed. Any station that has used all the items in stock cannot fill any more orders. At the end of the line orders are either completed or incomplete due to a lack of inventory at one or more stations. The simulator lists the completed orders and those that are incomplete once the line manager has finished processing all orders.

The project is divided into 3 milestones to show you through implementation, debugging and execution due to its complexity.

## Milestone 1

**Utilities and Station modules**

- The `Utilities` module supports the parsing of input files, which contain information used to setup and configure the assembly line.
- The `Station` module manages information about a station on the assembly line, which holds a specific item and fills customer orders.

## Milestone 2

**CustomerOrder module**

The `CustomerOrder` module contains all the functionality for processing customer orders as they move from `Station` to `Station` along the assembly line. The `Station` where a given order currently rests fills a request for one item of that station, if there is any such request.

## Milestone 3

**Workstation and LineManager modules**

The `LineManager` module first configures the assembly line and then moves `CustomerOrders` along it (from start to finish). The `LineManager` object configures the `Workstation` objects identified by the user, and moves orders along the line one step at a time. A `Workstation` is a `Station` that the `LineManager` has activated on the user's request. At each step, every `Workstation` fills one item in a `Customer Order`, if possible. The manager moves orders from station to station. Once an order has reached the end of the line, it is either complete or incomplete. An order is incomplete if one or more stations had an insufficient number of items in stock to cover that order's requests.
