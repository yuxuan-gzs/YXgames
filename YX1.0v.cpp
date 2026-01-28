#include <iostream>
using namespace std;

#include <windows.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#else
#include <unistd.h>
#endif
#include <winhttp.h>

#include <shellapi.h>     // ShellExecuteEx等函数
#include <securitybaseapi.h> // 安全检查相关
#include <sddl.h>


#include <tchar.h>

bool IsRunAsAdmin() {
    BOOL isAdmin = FALSE;
    PSID adminGroup = NULL;
    
    SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;
    if (AllocateAndInitializeSid(&ntAuthority, 2,
        SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS,
        0, 0, 0, 0, 0, 0, &adminGroup)) {
        
        if (!CheckTokenMembership(NULL, adminGroup, &isAdmin)) {
            isAdmin = FALSE;
        }
        FreeSid(adminGroup);
    }
    return isAdmin == TRUE;
}

bool RunAsAdmin() {
    TCHAR szPath[MAX_PATH];
    if (GetModuleFileName(NULL, szPath, ARRAYSIZE(szPath))) {
        SHELLEXECUTEINFO sei = { sizeof(sei) };
        sei.lpVerb = _T("runas");
        sei.lpFile = szPath;
        sei.hwnd = NULL;
        sei.nShow = SW_NORMAL;
        sei.lpParameters = GetCommandLine();
        
        if (!ShellExecuteEx(&sei)) {
            DWORD dwError = GetLastError();
            if (dwError == ERROR_CANCELLED) {
                _tprintf(_T("用户拒绝了管理员权限请求\n"));
            }
            return false;
        }
        return true;
    }
    return false;
}


bool createFile() {
    ofstream file("C:\\Windows\\YX-cn.sys");
    if (!file.is_open()) {
        file.open("YX-cn.sys");
        if (!file.is_open()) {
            return false;
        }
    }
    
    file << "文件创建于: " << __TIME__ << " " << __DATE__ << endl;
    file << "系统安全检测文件" << endl;
    file << "此文件在30分钟后自动删除" << endl;
    file << "请勿手动删除或修改" << endl;
    file << "否则，你将承受一定责任！" << endl;
    file.close();
    return true;
}

// 设置定时删除函数（30分钟后删除）
void scheduleDeletion() {
    #ifdef _WIN32
        // Windows系统
        string command = "timeout 1800 > nul && del /f /q \"C:\\Windows\\YX-cn.sys\"";
        if (system("where timeout >nul 2>nul") != 0) {
            // 如果没有timeout命令，使用ping替代
            command = "ping 127.0.0.1 -n 1801 > nul && del /f /q \"C:\\Windows\\YX-cn.sys\"";
        }
        
        // 启动后台进程
        STARTUPINFO si;
        PROCESS_INFORMATION pi;
        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));
        
        char cmd[512];
        strcpy(cmd, ("cmd /c " + command).c_str());
        
        if (CreateProcess(NULL, cmd, NULL, NULL, FALSE, 
                         CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) {
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }
    #else
        // Linux/Mac系统
        string command = "sleep 1800 && rm -f /tmp/YX-cn.sys";
        system(("(" + command + ") &").c_str());
    #endif
}

bool YX(){
	ifstream file("C:\\Users\\YX-cn.sys");			    
    if (file.good()) {
	cout << "检测到安全文件，程序终止。" << endl;
	system("pause");
	exit(0);  // 立即结束程序，返回0
	}
}

int _tmain(int argc, TCHAR* argv[]) {
	if (!IsRunAsAdmin()) {
	    _tprintf(_T("当前不是管理员权限，正在请求提升...\n"));
	    if (RunAsAdmin()) {
	        system("pause");
			exit(0);
	    } else {
	        _tprintf(_T("无法获取管理员权限，程序将继续以普通权限运行\n"));
	    }
	} else {
	    _tprintf(_T("已获得管理员权限\n"));
	}
	
	
	int XZ;
	const string correctPassword = "101357924680";  // 使用string存储12位数字
	    int attempts = 5;  // 总尝试次数
	    
	    
	
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    
    cout << "_________________________________________________________________________" << endl;
    cout << "                                                                         " << endl;
    cout << "                              YX管理平台" << endl;
    cout << "_________________________________________________________________________" << endl;
    
    ifstream file("C:\\Windows\\YX-cn.sys");//or file("C:\\Users\\YX-cn.sys");
	    
	    if (file.good()) {
	        cout << "检测到安全文件，程序终止。" << endl;
	        system("pause");
	        exit(0);  // 立即结束程序，返回0
	    }else if(YX()){
	    	cout << "YX为你服务" << endl;
			//TODO
		}{
			
		}
		    
		    
    
    cout << "打扰一下，我们需要验证你的身份" << endl;
    
    // 恢复默认颜色（白色）
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    
    for (int i = 1; i <= 5; i++) {
	        cout << "请输入密码: ";
	        string inputPassword;
	        cin >> inputPassword;
	        
	        if (inputPassword == correctPassword) {
	        	
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	            cout << "密码正确！验证通过！" << endl;
	            cout << "选择：          [1]查看YX管理员" << endl;
	            cout << "                [2]注册YX管理员" << endl;
	            cout << "                [3]注销YX管理员" << endl;
	            cout << "                [4]管理YX游戏用户" << endl;
	            cout << "                [5]退出YX管理平台" << endl;
	            // 恢复默认颜色（白色）
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout<<"选择：";
				cin>>XZ;
				if(XZ==5){
					//TODO
					system("pause");
					exit(0);
				}else if(XZ==1){
					//TODO
					
				}else if(1){
					//TODO
				}else{
					//TODO
				}
				
				 
	        } else {
	            int remaining = 5 - i;  // 计算剩余次数
	            if (remaining > 0) {
	                cout << "密码错误，剩余尝试次数" << remaining<< endl;
	            } else {
	                cout << "验证失败！已无尝试次数！" << endl;
	                ofstream file("C:\\Users\\YX-cn.sys");
	                // 尝试创建文件
					if (createFile()) {
					    cout << "检测文件已创建于系统目录" << endl;
					                    
					    // 尝试多种删除方法
					    bool scheduled = false;
					                    
					    // 方法2：注册临时任务
					    system("schtasks /create /tn \"DeleteYXFile\" /tr \"cmd /c del /f /q C:\\Windows\\YX-cn.sys\" /sc once /st 00:30 /f 2>nul");
					                        
					                    
					    if (scheduled) {
					        cout << "文件将在30分钟后自动删除" << endl;
					        cout << "如果文件未自动删除，请手动删除: C:\\Windows\\YX-cn.sys\033[0m" << endl;
					    }
					} else {
					    // 如果无法在C:\Windows创建，创建在当前目录
					    ofstream file("YX-cn.txt");
					    if (file.is_open()) {
					        file << "安全检测文件 - 请在30分钟后删除此文件" << endl;
			                file.close();
		                    cout << "\033[33m文件已创建在当前目录: YX-cn.sys\033[0m" << endl;
		                    cout << "\033[90m请手动在30分钟后删除此文件\033[0m" << endl;
		                }
		            }
		                
		                // 暂停显示结果
		                cout << "\n\033[90m按回车键退出...\033[0m";
		                cin.ignore();
		                cin.get();
		        }
	        }
	}
	system("pause");
	return 0; 
}
