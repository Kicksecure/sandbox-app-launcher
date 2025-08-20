# application launcher to start apps in a restrictive sandbox #

sandbox-app-launcher runs each app as its own user, in a bubblewrap sandbox
and confined by apparmor.

The directory, `/shared`, is shared across all app sandboxes to transfer
files across.

This implements a permissions system to configure what apps can access.
There are currently 5 available permissions:

* Network access

* Webcam access

* Microphone access

* Shared storage access (read-only or read-write)

* Dynamic native code execution

All apps the user installs will be automatically configured to run in
the sandbox and a prompt will ask the user which permissions they wish to
grant the application (not implemented yet).

Currently a WIP and not for actual use.

## How to install `sandbox-app-launcher` using apt-get ##

1\. Download the APT Signing Key.

```
wget https://www.kicksecure.com/keys/derivative.asc
```

Users can [check the Signing Key](https://www.kicksecure.com/wiki/Signing_Key) for better security.

2\. Add the APT Signing Key.

```
sudo cp ~/derivative.asc /usr/share/keyrings/derivative.asc
```

3\. Add the derivative repository.

```
echo "deb [signed-by=/usr/share/keyrings/derivative.asc] https://deb.kicksecure.com trixie main contrib non-free" | sudo tee /etc/apt/sources.list.d/derivative.list
```

4\. Update your package lists.

```
sudo apt-get update
```

5\. Install `sandbox-app-launcher`.

```
sudo apt-get install sandbox-app-launcher
```

## How to Build deb Package from Source Code ##

Can be build using standard Debian package build tools such as:

```
dpkg-buildpackage -b
```

See instructions.

NOTE: Replace `generic-package` with the actual name of this package `sandbox-app-launcher`.

* **A)** [easy](https://www.kicksecure.com/wiki/Dev/Build_Documentation/generic-package/easy), _OR_
* **B)** [including verifying software signatures](https://www.kicksecure.com/wiki/Dev/Build_Documentation/generic-package)

## Contact ##

* [Free Forum Support](https://forums.kicksecure.com)
* [Premium Support](https://www.kicksecure.com/wiki/Premium_Support)

## Donate ##

`sandbox-app-launcher` requires [donations](https://www.kicksecure.com/wiki/Donate) to stay alive!
