# TGTDB — TGit-Tech Debug

**Lightweight compile-time debugging macros for Arduino and C++.**

TGTDB provides a consistent debugging interface for errors, program flow, and informational messages. It supports general diagnostics and independently selectable code sections.

The primary design objective is simplicity: debugging code should impose no runtime overhead when disabled.

## Features

- Compile-time ON/OFF control.
- Three diagnostic types: `ERROR`, `ENTER`, and `INFO`.
- Seven independently selectable code sections.
- Zero to three argument variables accompanying a message.
- Direct Serial output variants (`SP`).
- Uses Arduino `F()` macro for diagnostic strings to conserve SRAM.
- Disabled macros expand to nothing.

## 1. Compile-Time Configuration

TGTDB uses preprocessor definitions to control debugging.

All importance levels and code sections default to `0` if not previously defined.

```cpp
#ifndef DB_ERROR
  #define DB_ERROR 0
#endif

#ifndef DB_ENTER
  #define DB_ENTER 0
#endif

#ifndef DB_INFO
  #define DB_INFO 0
#endif

#ifndef DB_GEN
  #define DB_GEN 0
#endif

#ifndef DBUI
  #define DBUI 0
#endif

#ifndef DBHW
  #define DBHW 0
#endif

#ifndef DBDB
  #define DBDB 0
#endif

#ifndef DBL
  #define DBL 0
#endif

#ifndef DBH
  #define DBH 0
#endif

#ifndef DBS
  #define DBS 0
#endif
```

Definitions made before including `TGTDB.h` override these defaults.

### Importance Levels

| Definition | Purpose |
|---|---|
| `DB_ERROR` | Error messages |
| `DB_ENTER` | Program flow / function entry |
| `DB_INFO` | Informational messages |

### Code Sections

| Definition | Section |
|---|---|
| `DB_GEN` | General — no specific section |
| `DBUI` | User Interface |
| `DBHW` | Hardware |
| `DBDB` | Database |
| `DBL` | Links / Communications |
| `DBH` | Helpers |
| `DBS` | System |

A diagnostic macro is active only when **both** its importance level and its code section are enabled.

For example:

```cpp
#define DB_ERROR 1
#define DB_ENTER 0
#define DB_INFO  1

#define DBHW 1
#define DBUI 0

#include <TGTDB.h>
```

This enables hardware errors and informational messages, but disables hardware entry messages and all UI diagnostics.

## 2. Disabled Macros — Zero Runtime Overhead

This is a fundamental feature of TGTDB.

When a diagnostic is disabled, its macro expands to nothing.

For example:

```cpp
#if (DB_ERROR && DBHW)
#define DBHWERROR(z) Serial.print(F("!ERROR!HW "));SERLINEZ(z)
#else
#define DBHWERROR(z)
#endif
```

When `DB_ERROR` or `DBHW` is `0`, the macro produces no executable code.

This means:

- No Serial output.
- No runtime conditional checks.
- No function calls.
- No diagnostic strings stored in program memory.
- No diagnostic variables evaluated at runtime.

The compiler never receives the disabled diagnostic statement as executable code.

**TGTDB is compile-time debugging, not runtime logging.**

## 3. Diagnostic Types

TGTDB provides three diagnostic types.

| Type | Output prefix | Purpose |
|---|---|---|
| ERROR | `!ERROR!` | Error reporting |
| ENTER | `__>` | Program flow and entry tracing |
| INFO | `...` | Informational output |

Code-section prefixes are appended to the diagnostic identifier.

Examples:

```text
!ERROR!HW
__HW>
...HW
```

## 4. Macro Argument Formats

Each diagnostic type supports four macro forms.

The forms allow zero through three argument variables, followed by the message.

| Form | Arguments | Example |
|---|---:|---|
| Base | Message only | `DBERROR(("Error"))` |
| A | 1 variable + message | `DBAERROR((Value),("Error"))` |
| AA | 2 variables + message | `DBAAERROR((A),(B),("Error"))` |
| AAA | 3 variables + message | `DBAAAERROR((A),(B),(C),("Error"))` |

The additional parentheses around each argument are intentional. They allow the macros to handle comma-containing expressions.

### Examples

```cpp
DBERROR(("Pump failed"))

DBAERROR((PumpID),("Pump failed"))

DBAAERROR((PumpID),(Pressure),("Low pressure"))

DBAAAERROR((PumpID),(Pressure),(Voltage),("Pump failure"))
```

The argument variables are printed with commas between them and a closing parenthesis before the message.

Example output:

```text
!ERROR! (1,45,24)Pump failure
```

## 5. Code-Section Macros

Each code section has its own complete set of diagnostic macros.

### General (GEN)

No section identifier is included in the output.

```cpp
DBERROR(("Message"))
DBENTER(("Message"))
DBINFO(("Message"))
```

### User Interface (UI)

```cpp
DBUIERROR(("Message"))
DBUIENTER(("Message"))
DBUIINFO(("Message"))
```

### Hardware (HW)

```cpp
DBHWERROR(("Message"))
DBHWENTER(("Message"))
DBHWINFO(("Message"))
```

### Database (DB)

```cpp
DBDBERROR(("Message"))
DBDBENTER(("Message"))
DBDBINFO(("Message"))
```

### Links (L)

```cpp
DBLERROR(("Message"))
DBLENTER(("Message"))
DBLINFO(("Message"))
```

### Helpers (H)

```cpp
DBHERROR(("Message"))
DBHENTER(("Message"))
DBHINFO(("Message"))
```

### System (S)

```cpp
DBSERROR(("Message"))
DBSENTER(("Message"))
DBSINFO(("Message"))
```

Every section supports the same argument-count variants (`A`, `AA`, and `AAA`).

## 6. Direct Serial Output (SP)

Each diagnostic type and section also provides an `SP` variant.

These macros bypass the normal diagnostic prefix and print directly to Serial.

Examples:

```cpp
DBERRORSP(("Raw output"))
DBENTERSP(("Raw output"))
DBINFOSP(("Raw output"))

DBHWERRORSP(("Raw hardware output"))
DBUIINFOSP(("Raw UI output"))
```

SP macros are still controlled by their corresponding importance-level and section switches. They do not bypass compile-time disabling.

## 7. Newlines

TGTDB does not automatically append a newline.

Use `\n` in the message when a new line is required.

```cpp
DBERROR(("Pump failed\n"))

DBINFO(("System initialized\n"))
```

Without `\n`, subsequent output continues on the same line.

## 8. Arduino Requirements

TGTDB currently uses:

- `Serial.print()`
- Arduino's `F()` macro

Initialize Serial in your sketch before expecting diagnostic output:

```cpp
void setup() {
    Serial.begin(115200);
}
```

TGTDB is designed for Arduino-style embedded projects.

## 9. Recommended Usage

Use the diagnostic types consistently:

- `ERROR` — Something went wrong.
- `ENTER` — Trace program execution.
- `INFO` — Report useful operating information.

Use code sections to distinguish the origin of diagnostics.

For example:

```cpp
DBHWENTER(("Starting pump control"));

DBHWINFO(("Pressure: "));
DBHWERROR(("Pressure sensor failure\n"));

DBLINFO(("RF packet received\n"));

DBSENTER(("System initialization"));
```

This makes Serial output easier to interpret when multiple subsystems are operating.

---

**TGit-Tech**

Engineering over marketing.