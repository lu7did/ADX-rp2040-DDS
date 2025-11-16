# Contributing to ADX-rp2040-DDS

Thank you for your interest in contributing to the ADX-rp2040-DDS project!

## Project Status

This project is in **early experimental stage**. We welcome contributions of all kinds.

## How to Contribute

### Reporting Issues

- Use GitHub Issues to report bugs
- Include detailed description of the problem
- Provide steps to reproduce
- Include hardware configuration
- Add relevant log output

### Suggesting Enhancements

- Open an issue with [ENHANCEMENT] prefix
- Describe the feature clearly
- Explain the use case
- Consider backward compatibility

### Code Contributions

1. **Fork the Repository**
   ```bash
   git clone https://github.com/lu7did/ADX-rp2040-DDS.git
   cd ADX-rp2040-DDS
   ```

2. **Create a Branch**
   ```bash
   git checkout -b feature/your-feature-name
   ```

3. **Make Changes**
   - Follow the coding style (see below)
   - Add comments for complex logic
   - Test your changes thoroughly

4. **Commit Changes**
   ```bash
   git add .
   git commit -m "Add: brief description of changes"
   ```

5. **Push and Create PR**
   ```bash
   git push origin feature/your-feature-name
   ```
   Then create a Pull Request on GitHub

## Coding Standards

### C Code Style

- Use 4 spaces for indentation (no tabs)
- Maximum line length: 100 characters
- Use descriptive variable names
- Comment complex algorithms
- Follow existing code patterns

### Example:
```c
// Good
bool dds_set_frequency(uint32_t frequency) {
    if (frequency > DDS_MAX_FREQUENCY) {
        return false;
    }
    // Set frequency...
    return true;
}

// Avoid
bool f(uint32_t x){if(x>MAX){return false;}return true;}
```

### File Organization

- Header files (.h) in same directory as source (.c)
- Use include guards in all headers
- Group related functions together
- Separate hardware and protocol layers

### Documentation

- Document all public functions
- Use Doxygen-style comments
- Keep README.md updated
- Update API.md for API changes

## Testing

### Before Submitting

- [ ] Code compiles without errors
- [ ] Code compiles without warnings
- [ ] Tested on actual hardware (if possible)
- [ ] No regression in existing features
- [ ] Documentation updated

### Hardware Testing

If you have hardware:
- Test on Raspberry Pi Pico
- Verify all GPIO functions
- Check USB connectivity
- Measure RF output (with appropriate equipment)

## Development Environment

### Required Tools
- CMake 3.13+
- ARM GCC toolchain
- Raspberry Pi Pico SDK
- Git

### Recommended Tools
- VSCode with C/C++ extension
- Logic analyzer for debugging
- Oscilloscope for RF testing

## Communication

- Use GitHub Issues for public discussion
- Tag issues appropriately
- Be respectful and constructive
- Help others when you can

## Areas Needing Help

### High Priority
- [ ] Complete FT8 encoding/decoding
- [ ] Optimize DDS implementation
- [ ] Full USB audio device support
- [ ] Hardware testing and validation

### Medium Priority
- [ ] Additional digital modes (PSK31, RTTY)
- [ ] Configuration interface
- [ ] Documentation improvements
- [ ] Example code and tutorials

### Future Ideas
- [ ] Web interface for control
- [ ] Waterfall display
- [ ] Band scope
- [ ] CW mode support

## License

By contributing, you agree that your contributions will be licensed under the MIT License.

## Questions?

Open an issue with [QUESTION] prefix or contact the maintainer.

## Acknowledgments

Contributors will be acknowledged in the project documentation.

Thank you for contributing to ADX-rp2040-DDS! 🎉
