#include "pch.h"
#include<iostream>


void ROV()
{
	//����9�������������������
	/*
	function [vertices_Mutual, faces_Mutual, n_rem] = RemovingOldVertices_cpp2(...
    mymesh, vertices_cand, faces_Mutual, CSP_idx)
	*/
	//mesh.
	double vertices, norm_face; //������ʽ��norm_face����--��������
	//double sa��si; //���������ÿ��С�����������

	int np, nf;
	int faces; //������ʽ
	int hedge_face; //ϡ����󣬰��--��
	//����������
	double vertices_cand; // ���������
	int faces_Mutual;//ÿ�������ӹ�ϵ
	int CSP_idx;//�̶��ĵ㣬������Ի��� (1:np-CSP_idx);

	//���
	double vertices_Mutual; //���ɵ����񶥵�
	//int faces_Mutual; //���ɵ���
	int n_rem; //ԭ�����������ĵ�


	/*************
	1.��������Ϣ�����������У������������������ʽ
	2.RemoveOldVertices��c++�е�ʵ�����̣�
	(1)Ѱ�ҵ�P�������
	(2)�ж�������Ƿ���ͶӰ,�����֮��û�н�����test1��
	(3)��ͶӰƽ����Ѱ�� critical edge��
		����ڶ�����ڲ����� critical edge�������Ͳ���ȥ����test2��
	(4)ȥ��ԭʼ����󣬽�������������ǻ�����collapse�����ܻ�������������
	(5)������Ͷ�����Ϣ
	(6)ѭ��
	***************/

	//����дcpp֮ǰ��Ҫ���һ�������⣺֮ǰ��������� findNearPsʧЧ��ô����





	//return 0;
}
