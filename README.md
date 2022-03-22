# gnandas
My solution to the Quantcast Internship Interview.
Here I make a small dataframe class optimised to query the most occuring cookie for a given day. As an example of this repo's capabilities, I'll use it to solve [this](https://github.com/ethangnibus/gnandas/files/8322796/Quantcast.coding_task.Exercise.1.docx) spec:

Directions:
1) Generating executables 
Before running anything, make sure you are in the gnandas directory. If you run the "pwd" command in console your terminal should output something like "~/gnandas/". While in the gnandas directory, run the "make" command to generate the project executables. This will generate the most_active_cookie executable, "most_active_cookie.o", and "Dataframe.o". You can also run "make test_unit" to generate the executables for the project's testing unit. This will generate the test_unit executable, "test_unit.o", and "Dataframe.o". If you want to delete all associated executables, you can always run "make clean". This will delete the most_active_cookie executable, "most_active_cookie.o", the test_unit executable, "test_unit.o", and "Dataframe.o".

2) Running the test_unit executable
While in the gnandas directory, run "./test_unit" to run all tests. You can read the code behind these tests by looking at "gnandas/test_unit.cpp".

3) Running the most_active_cookie executable
While in the gnandas directory, run:
./most_active_cookie <path_to_csv> -d <date>
where you replace <path_to_csv> and <date> with the relative path to the csv you want to query and date you want to query over respectively.

For example, to run the test from the spec we could run:
./most_active_cookie cookie_log.csv -d 2018-12-09
