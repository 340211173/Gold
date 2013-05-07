//IOCTL.h
#define	FILE_DRIVER_SSDT	0x0000420
#define	SystemModuleInfo	0x0B

#define	DRIVER_NAME		L"\\Device\\SSDT"
#define	DEVICE_NAME		L"\\DosDevices\\SSDT"

#ifndef CTL_CODE
#define CTL_CODE( DeviceType, Function, Method, Access ) (                 \
    ((DeviceType) << 16) | ((Access) << 14) | ((Function) << 2) | (Method) \
)
#endif // CTL_CODE

#ifndef METHOD_NEITHER
#define METHOD_NEITHER 3
#endif // METHOD_NEITHER

#define IOCTL_TCP_QUERY_INFORMATION_EX 0x00120003
#define	HTONS(a)	(((0xff&a)<<8)+((0xff00&a)>>8))

#define TCPPORT	0
#define UDPPORT	1

typedef struct _CONNINFO102
{
	ULONG	status;
	ULONG	src_addr;
	USHORT	src_port;
	USHORT	unk1;
	ULONG	dst_addr;
	USHORT	dst_port;
	USHORT	unk2;
	ULONG	pid;
} CONNINFO102,*PCONNINFO102;

typedef	struct _UDPCONNINFO
{
	ULONG	src_addr;
	USHORT	src_port;
	ULONG	pid;
}	UDPCONNINFO,*PUDPCONNINFO;

NTSTATUS	
GetObjectByName(
				OUT HANDLE *FileHandle,
				OUT PFILE_OBJECT	*FileObject,
				IN WCHAR	*DeviceName
				);

PVOID		
EnumPortInformation(
					OUT PULONG	OutLength,
					IN	USHORT	PortType
	);


//////////////////////////////////////////////////////////////////////////
//SSDT �ṹ��
typedef struct _tagSSDT {
    PVOID pvSSDTBase;
    PVOID pvServiceCounterTable;
    ULONG ulNumberOfServices;
    PVOID pvParamTableBase;
} MYSSDT, *PMYSSDT;
/////////////////////////////////////////////////////////////////////////
// ModuleInfo �ṹ��
typedef struct ModuleInfo_t {
	ULONG Unused;
	ULONG Always0;
	ULONG ModuleBaseAddress;
	ULONG ModuleSize;
	ULONG Unknown;
	ULONG ModuleEntryIndex;
	/* Length of module name not including the path, this field contains valid value only for NTOSKRNL module*/
	USHORT ModuleNameLength; 
	USHORT ModulePathLength; /*Length of 'directory path' part of modulename*/
	char ModuleName[256];
} DRIVERMODULEINFO, *PDRIVERMODULEINFO;
////////////////////////////////////////////////////////////////////
//��ȡSSDT�ṹ
#define IOCTL_GETSSDT  (ULONG)CTL_CODE( FILE_DRIVER_SSDT, 0x01, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA )

//����SSDT�ṹ
#define IOCTL_SETSSDT  (ULONG)CTL_CODE( FILE_DRIVER_SSDT, 0x02, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA )

//��ѯSSDT HOOK������ַ
#define IOCTL_GETHOOK  (ULONG)CTL_CODE( FILE_DRIVER_SSDT, 0x03, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA )

//����SSDT HOOK������ַ
#define IOCTL_SETHOOK  (ULONG)CTL_CODE( FILE_DRIVER_SSDT, 0x04, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA )

//��NtQuerySystemInformation��ַ��������
#define IOCTL_QSIADDR  (ULONG)CTL_CODE( FILE_DRIVER_SSDT, 0x05, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA )

//��NtDeviceIoControlFile��ַ��������
#define IOCTL_DICFADDR  (ULONG)CTL_CODE( FILE_DRIVER_SSDT, 0x06, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA )

//ǿɱ����
#define IOCTL_KILL  (ULONG)CTL_CODE( FILE_DRIVER_SSDT, 0x07, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA )

//����ע�����
#define IOCTL_REG_PROTECTION  (ULONG)CTL_CODE( FILE_DRIVER_SSDT, 0x08, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA )

//ֹͣע�����
#define IOCTL_STOP_PROTECTION  (ULONG)CTL_CODE( FILE_DRIVER_SSDT, 0x09, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA )

//���¼���������
#define IOCTL_SAVE_EVENT  (ULONG)CTL_CODE( FILE_DRIVER_SSDT, 0x10, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA )

//���ע�����Ϣ
#define IOCTL_REGISTRY_INFO  (ULONG)CTL_CODE( FILE_DRIVER_SSDT, 0x11, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA )

//�����޸�
#define IOCTL_ALLOW_MODIFY  (ULONG)CTL_CODE( FILE_DRIVER_SSDT, 0x12, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA )

//ö��TCP
#define IOCTL_ENUMTCP (ULONG)CTL_CODE( FILE_DRIVER_SSDT, 0x13, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA )

//ö��UDP
#define IOCTL_ENUMUDP (ULONG)CTL_CODE( FILE_DRIVER_SSDT, 0x14, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA )
