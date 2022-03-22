# gnandas
A small clone of pandas in c++. As an example of this repo's capabilities, I'll use it to solve the following spec:

Most Active Cookie
Given a cookie log file in the following format:
cookie,timestamp
AtY0laUfhglK3lC7,2018-12-09T14:19:00+00:00
SAZuXPGUrfbcn5UA,2018-12-09T10:13:00+00:00
5UAVanZf6UtGyKVS,2018-12-09T07:25:00+00:00
AtY0laUfhglK3lC7,2018-12-09T06:19:00+00:00
SAZuXPGUrfbcn5UA,2018-12-08T22:03:00+00:00
4sMM2LxV07bPJzwf,2018-12-08T21:30:00+00:00
fbcn5UAVanZf6UtG,2018-12-08T09:30:00+00:00
4sMM2LxV07bPJzwf,2018-12-07T23:30:00+00:00
Write a command line program in your preferred language to process the log file and return the most active
cookie for specified day. The example below shows how we&#39;ll execute your program.
Command:
$ ./most_active_cookie cookie_log.csv -d 2018-12-09
Output:
AtY0laUfhglK3lC7
We define the most active cookie as one seen in the log the most times during a given day.
Assumptions:
 If multiple cookies meet that criteria, please return all of them on separate lines.
$ ./most_active_cookie cookie_log.csv -d 2018-12-08
SAZuXPGUrfbcn5UA
4sMM2LxV07bPJzwf
fbcn5UAVanZf6UtG
 You&#39;re only allowed to use additional libraries for testing, logging and cli-parsing. There are libraries for
most languages which make this too easy (e.g pandas) and we’d like you to show off you coding skills.
 You can assume -d parameter takes date in UTC time zone.
 You have enough memory to store the contents of the whole file.
 Cookies in the log file are sorted by timestamp (most recent occurrence is first line of the file).
We&#39;re looking for a concise, maintainable, extendable and correct solution. We&#39;re hoping you&#39;ll deliver your
solution as production grade code and demonstrate:
 good testing practices,
 knowledge of build systems, testing frameworks, etc.
 clean coding practices (meaningful names, clean abstractions, etc.)
Please use a programming language you’re very comfortable with. The next stage of the
interview will involve extending your code.


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