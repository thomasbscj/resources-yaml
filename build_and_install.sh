#!/bin/bash

set -e

BINARY_NAME="kymlgen"
SOURCE_FILE="main.c resourceFunctions.c verifyIsTerminated.c"
INSTALL_DIR="$HOME/.local/bin"
SHELL_RC=""

if [ -n "$ZSH_VERSION" ]; then
  SHELL_RC="$HOME/.zshrc"
elif [ -n "$BASH_VERSION" ]; then
  SHELL_RC="$HOME/.bashrc"
else
  SHELL_RC="$HOME/.profile"
fi

echo "Compiling $SOURCE_FILE -> $BINARY_NAME..."
gcc "$SOURCE_FILE" -o "$BINARY_NAME"

echo "Installing in $INSTALL_DIR..."
mkdir -p "$INSTALL_DIR"
cp "$BINARY_NAME" "$INSTALL_DIR/"
chmod +x "$INSTALL_DIR/$BINARY_NAME"
rm -f "./$BINARY_NAME"

if grep -q 'export PATH="\$HOME/.local/bin:\$PATH"' "$SHELL_RC"; then
  echo "PATH configured $SHELL_RC"
else
  echo "Adding $INSTALL_DIR to PATH in $SHELL_RC"
  echo '' >> "$SHELL_RC"
  echo 'export PATH="$HOME/.local/bin:$PATH"' >> "$SHELL_RC"
fi

echo "Done."
echo "Execute: source $SHELL_RC"
echo "Then, use: $BINARY_NAME"