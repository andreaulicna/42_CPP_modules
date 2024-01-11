# 42_CPP_Modules

## CPP_Module_00

### ex02

#### Testing
There are 2 bash scripts to make the testing (comparison between the original log and the recreated one) easier in VS Code.
- The first one executes the program, redirects the output into recreated.log and
creates comparison files.
- The second one cleans up the recreated.log and comparison files once comparison is done.
```
cd compare_logs
bash compare_logs.sh
bash compare_logs_cleanup.sh
```