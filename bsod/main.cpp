//Dev-C++ ����ͨ��
//win7 win10���Գɹ�
#include <stdio.h>
#include <windows.h>

typedef enum _HARDERROR_RESPONSE_OPTION {
OptionAbortRetryIgnore,
OptionOk,
OptionOkCancel,
OptionRetryCancel,
OptionYesNo,
OptionYesNoCancel,
OptionShutdownSystem
} HARDERROR_RESPONSE_OPTION, *PHARDERROR_RESPONSE_OPTION;

typedef enum _HARDERROR_RESPONSE {
ResponseReturnToCaller,
ResponseNotHandled,
ResponseAbort,
ResponseCancel,
ResponseIgnore,
ResponseNo,
ResponseOk,
ResponseRetry,
ResponseYes
} HARDERROR_RESPONSE, *PHARDERROR_RESPONSE;

typedef struct _UNICODE_STRING {
USHORT Length;
USHORT MaximumLength;
PWSTR Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

typedef void (__stdcall *ER)(ULONG, ULONG, PUNICODE_STRING, PVOID, HARDERROR_RESPONSE_OPTION, OUT PHARDERROR_RESPONSE);
typedef BOOL (__stdcall *PR)(ULONG, BOOL, BOOL, PBOOLEAN);

ER NtRaiseHardError;
PR RtlAdjustPrivilege;

const ULONG SE_DEBUG_PRIVILEGE = 20;
const ULONG SE_SHUTDOWN_PRIVILEGE = 19;

void CallBlueScreen(ULONG ErrorCode) {//ErrorΪ����Ҫ������������
BOOLEAN B;
RtlAdjustPrivilege = (PR)GetProcAddress(GetModuleHandle("ntdll.dll"), "RtlAdjustPrivilege");
NtRaiseHardError = (ER)GetProcAddress(GetModuleHandle("ntdll.dll"), "NtRaiseHardError");
RtlAdjustPrivilege(SE_DEBUG_PRIVILEGE, TRUE, FALSE, &B);
RtlAdjustPrivilege(SE_SHUTDOWN_PRIVILEGE, TRUE, FALSE, &B);
HARDERROR_RESPONSE OR;
OR = ResponseYes;
NtRaiseHardError(ErrorCode, 0, 0, 0, OptionShutdownSystem, &OR);
}
int main() {
CallBlueScreen(0xc2501841);//������Ϊ����Ҫ������������
}

