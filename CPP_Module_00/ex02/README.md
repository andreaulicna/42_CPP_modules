# 42_CPP_Modules

## CPP_Module_00

### ex01

#### Testing
- Input:
    - Enter
    - Ctrl + C and Ctrl + D
- ADD:
    - adding contacts when the phonebook is full
        - how easily can be a contact overwritten
        - does the history (oldest saved) shifts?
- SEARCH:
    - obviously invalid index such as 'a', 'hello'
    - entry > 8 vs entry <= 8 when there are not yet 8 contacts saved
    - valid index when there are no contacts saved yet
    - printing of empty rows

### ex02

#### Testing
There are 2 bash scripts to make the testing (comparison between the original log and the recreated one) easier in VS Code.
- The first one executes the program, redirects the output into recreated.log and
creates comparison files.
- The second one cleans up the recreated.log and comparison files once the comparison is done.
```
cd compare_logs
bash compare_logs.sh
bash compare_logs_cleanup.sh
```