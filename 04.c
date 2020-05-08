//������Ȃ�c�w���C�u�����g���Ă��{�{�ł��ق��������@visualstudio�A�v���P�[�V�����v���W�F�N�g�����������H
#include <windows.h>

#define SCW 1280
#define SCH 720

//�^�C�g���o�[�̖��O
#define TNAME "�T���v��"
//window�N���X�̖��O�i�K���ł�k�j
#define WCNAME "windowclass"

void InitWindow(HINSTANCE hInstance, const char* name, int width, int height);
//�E�C���h�E�v���V�[�W��
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

//�E�B���h�E�n���h��
HWND hWnd;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{


	//window�̏�����
	InitWindow(hInstance, TNAME, SCW, SCH);

	//���C�����[�v
	MSG hMsg;		//���b�Z�[�W�\���̕ϐ�
	while (1) {
		// ���b�Z�[�W�����邩�ǂ����𒲂ׂ�B
		if (PeekMessage(&hMsg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (!GetMessage(&hMsg, NULL, 0, 0))	 // hMsg �Ƀ��b�Z�[�W���i�[����
				break;
			TranslateMessage(&hMsg);	//�L�[���͂ɂ��đO����������֐��B�L�[���͂��Ȃ��ꍇ�͏ȗ����Ă��悢�B
			DispatchMessage(&hMsg);		//�E�B���h�E�v���V�[�W���ɂ��n���b�Z�[�W�n��
		}
		else {
			// �Q�[���̏���------

			//�G�X�P�[�v�L�[�ŏI��
			if (GetKeyState(VK_ESCAPE) & 0x8000) {
				break;
			}

		}
	}

	return 0;
}







//�E�C���h�E�v���V�[�W��
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_KEYDOWN:			//�L�[�������ꂽ�Ƃ�
		break;

	case WM_CLOSE:				//�E�B���h�E�����Ƃ�
		PostMessage(hWnd, WM_DESTROY, 0, 0);	//�v���V�[�W���Ƀ��b�Z�[�W�𑗂�
		break;

	case WM_DESTROY:			//����ꂽ�Ƃ�
		PostQuitMessage(0);		//�A�v���P�[�V������������Ƃ��ɌĂ�
		break;
	}

	return(DefWindowProc(hWnd, message, wParam, lParam));	//������̂�switch�̒��ɏ����A����Ȃ����̂�DefWindowProc�ŏ��������Ă���B
}

void InitWindow(HINSTANCE hInstance, const char* name, int width, int height)
{
	//�E�B���h�E�N���X��o�^

	WNDCLASS wcex;										//��܂��ȃE�B���h�E�̔ėp�I�Ȑݒ���s���N���X
	wcex.style = CS_HREDRAW | CS_VREDRAW;				//��{�X�^�C����\���萔
	wcex.lpfnWndProc = WndProc;							//�E�C���h�E�v���V�[�W���@���������C�x���g����������
	wcex.cbClsExtra = 0;								//�N���X�\���̂̒ǉ��̈���o�C�g�P�ʂŗ\�񂷂����		�����̏ꍇ0���w��
	wcex.cbWndExtra = 0;								//�E�B���h�E�\���̂̒ǉ��̈���o�C�g�P�ʂŗ\�񂷂����	�����̏ꍇ0���w��
	wcex.hInstance = hInstance;							//�C���X�^���X�n���h����n���B
	wcex.hIcon = NULL;									//�^�X�N�o�[��^�C�g���o�[�ɕ\�������A�C�R���̃r�b�g�}�b�v���w��
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW); 							//�}�E�X�J�[�\�����w�肵�܂�
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);	//�N���C�A���g�G���A�̔w�i�F���w��
	wcex.lpszMenuName = NULL;							//�N���X���j���[���w��
	wcex.lpszClassName = WCNAME;						//�E�B���h�E�N���X�̖��O���w��
	RegisterClass(&wcex);								//��ō�����E�C���h�E�N���X��o�^



	hWnd = CreateWindowEx(0,				//�g���X�^�C���̐ݒ� �t�@�C�����h���b�O�A���h�h���b�v�Ƃ�������
		WCNAME,								//�o�^����Ă���E�C���h�E�N���X�̖��O
		name,								//�E�C���h�E��
		WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_POPUP,	//�E�C���h�E�X�^�C��
		0,//CW_USEDEFAULT,						//�E�C���h�E�̉��ʒu�@�K���Ȉʒu��
		0,//CW_USEDEFAULT,						//�E�C���h�E�̏c�ʒu�@�K���Ȉʒu��
		width,								//�E�C���h�E�̕�
		height,								//�E�C���h�E�̍���
		NULL,								//�e�E�C���h�E�܂��̓I�[�i�[�E�C���h�E�̃n���h��
		NULL,								//���j���[�n���h���܂��͎q�E�C���h�EID
		hInstance,							//�A�v���P�[�V�����C���X�^���X�̃n���h��
		NULL);								//�E�C���h�E�쐬�f�[�^

}