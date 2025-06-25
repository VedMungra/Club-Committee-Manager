# Club-Committee-Manager
=> "club_manager_final.cpp" is Our Main Programme file.
=> "record.csv" is Our Database File which stores members data.
=> "clubs.csv" is file which stores all club list with its category
=> "Secret.txt" contain password which is needed to unlock some functionalities like add and delete members and also add and delete club. 

==================================================================================================================
Task :
=> You need to build a manager for all the DA-IICT clubs. The manager ensures that a club member can be looked up in minimum time. A member can either be a faculty or a student. One should be able to search by name, ID, specific club name, or club category (i.e., arts, science & technology, sports, culture). Note that the user of this manager may not be a DA-IICT-ian and, therefore, may not know the clubs’ names.

Our Approach :
=>	We have to Make the Club Management System for Particular Institute say DAIICT. In our System We Added Functionalities Like :
   •	Add New Member
   •	Delete Member
   •	View all Member List 
   •	Search Member
      -	Search By ID
     	- Search By Name
      -	Search By Club
   •	Add New Club
   •	Delete Club
   •	View Club List

=>	Here Main Part of Programme is that use of appropriate Data Structure. We have many options like link list with Enum, map, hash table etc. but we feel that the use of Hash Table is Appropriate to store data and also for search. It is More accurate than the map.

=>	Map sorts its elements implicitly in lexicographical order which increases the time complexity of basic operations such as Addition, Deletion of Members and Searching etc. also lexicographical sorting was not needed in our project.

=>	But we also Face some Difficulties like use of HashMap make search function by ID in O(1) and Search By Name and Club in O(n) and try keeping Space Complexity Low.
