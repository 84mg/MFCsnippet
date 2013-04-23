
BOOL CStalkerApp::InitInstance()
{
	
	if(NULL == ::OpenMutex(MUTEX_ALL_ACCESS, FALSE, _T("APP_NAME")))
	{
		m_hMutex = ::CreateMutex(NULL, FALSE, _T("APP_NAME"));
		if(m_hMutex == NULL)
		{
			AfxMessageBox(_T("APP_NAME is already running."), MB_OK|MB_ICONEXCLAMATION);
			return FALSE;
		}
	}
	else
	{
		CWnd* pWnd = NULL;
		pWnd = CWnd::FindWindow(NULL, _T("APP_NAME"));
		if(pWnd != NULL)
		{
			if(pWnd->IsIconic()) 
				pWnd->ShowWindow(SW_RESTORE);
			else    
				pWnd->SetForegroundWindow();
		}

		return FALSE;
	}  
}