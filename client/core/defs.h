#ifndef DEFS_H
#define DEFS_H

#include <QMetaEnum>
#include <QObject>

namespace amnezia {

struct ServerCredentials
{
    QString hostName;
    QString userName;
    QString password;
    int port = 22;

    bool isValid() const { return !hostName.isEmpty() && !userName.isEmpty() && !password.isEmpty() && port > 0; }
};

enum ErrorCode
{
    // General error codes
    NoError = 0,
    UnknownError,
    InternalError,
    NotImplementedError,

    // Server errors
    ServerCheckFailed,
    ServerPortAlreadyAllocatedError,
    ServerContainerMissingError,
    ServerDockerFailedError,

    // Ssh connection errors
    SshSocketError, SshTimeoutError, SshProtocolError,
    SshHostKeyError, SshKeyFileError, SshAuthenticationError,
    SshClosedByServerError, SshInternalError,

    // Ssh remote process errors
    SshRemoteProcessCreationError,
    FailedToStartRemoteProcessError, RemoteProcessCrashError,
    SshSftpError,

    // Local errors
    FailedToSaveConfigData,
    OpenVpnConfigMissing,
    OpenVpnManagementServerError,
    EasyRsaError,
    ConfigMissing,

    // Distro errors
    OpenVpnExecutableMissing,
    EasyRsaExecutableMissing,
    ShadowSocksExecutableMissing,
    CloakExecutableMissing,
    AmneziaServiceConnectionFailed,
    ExecutableMissing,

    // VPN errors
    OpenVpnAdaptersInUseError,
    OpenVpnUnknownError,
    OpenVpnTapAdapterError,

    // 3rd party utils errors
    OpenVpnExecutableCrashed,
    ShadowSocksExecutableCrashed,
    CloakExecutableCrashed
};

} // namespace amnezia

Q_DECLARE_METATYPE(amnezia::ErrorCode)

#endif // DEFS_H
