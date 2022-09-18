SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

EXECUTABLE_PATH="$SCRIPT_DIR/bin/helloworld"

${SCRIPT_DIR}/compile.sh
if [ $? -ne 0 ]; then
    exit 1
fi

if [[ ! -d "$SCRIPT_DIR/bin" ]] || [[ ! -f "$EXECUTABLE_PATH" ]]; then
    echo "$EXECUTABLEJ_PATH does not exist."
    exit 1
fi

${EXECUTABLE_PATH} "$@"
if [ $? -ne 0 ]; then
    exit 1
fi
