import requests

cookies = {
    '_ga': 'GA1.2.851805707.1658332963',
    'gr_user_id': '2ee6bb9f-3c50-429f-8bd6-f80f5d76d4a2',
    'csrftoken': 'FOnxnVD05cdmtHX4mmKayx5290ojy5y0rlHTip49wOTbMsprVAdAIWwK519UgPjr',
    '_gid': 'GA1.2.463271.1658914517',
    '__stripe_mid': '7ffe7d00-f6ab-42a0-859d-5b30ef94dbc2ba1c8c',
    '87b5a3c3f1a55520_gr_last_sent_cs1': 'tmanh17',
    'NEW_PROBLEMLIST_PAGE': '1',
    'LEETCODE_SESSION': 'eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfYXV0aF91c2VyX2lkIjoiMjU3MzcxMCIsIl9hdXRoX3VzZXJfYmFja2VuZCI6ImFsbGF1dGguYWNjb3VudC5hdXRoX2JhY2tlbmRzLkF1dGhlbnRpY2F0aW9uQmFja2VuZCIsIl9hdXRoX3VzZXJfaGFzaCI6IjVlY2JiY2JlMTFmMDY0YTU4ZWY1ZjJmY2Q2YmNiODNkODRmNDUwOWIiLCJpZCI6MjU3MzcxMCwiZW1haWwiOiJ0bWFuaDE3QGdtYWlsLmNvbSIsInVzZXJuYW1lIjoidG1hbmgxNyIsInVzZXJfc2x1ZyI6InRtYW5oMTciLCJhdmF0YXIiOiJodHRwczovL2Fzc2V0cy5sZWV0Y29kZS5jb20vdXNlcnMvdGllbl9tYW5oL2F2YXRhcl8xNTc5MzcxOTYxLnBuZyIsInJlZnJlc2hlZF9hdCI6MTY2MDMxMjg2NCwiaXAiOiIxNC4xNzcuMTEyLjIyOSIsImlkZW50aXR5IjoiZDNkNDA2OGExMWY0ZTBmNDRlNDUyN2IxMmZjNGI5OGYiLCJzZXNzaW9uX2lkIjoyNDc3NTA0MywiX3Nlc3Npb25fZXhwaXJ5IjoxMjA5NjAwfQ.knv3q7r4CdSjINMiFlirrGj78aj1Ftc6ksu73DDPI8g',
    '87b5a3c3f1a55520_gr_session_id': '64f6546c-b61e-4326-b038-79296d4ace27',
    '87b5a3c3f1a55520_gr_last_sent_sid_with_cs1': '64f6546c-b61e-4326-b038-79296d4ace27',
    '87b5a3c3f1a55520_gr_session_id_64f6546c-b61e-4326-b038-79296d4ace27': 'true',
    '__atuvc': '68%7C29%2C40%7C30%2C54%7C31%2C52%7C32',
    '__atuvs': '62f7ab8a6e718732003',
    'c_a_u': '"dG1hbmgxNw==:1oMrZR:l9Zkv5EykbtDXrOuHVtKhaKE0oc"',
    '87b5a3c3f1a55520_gr_cs1': 'tmanh17',
}

headers = {
    'authority': 'leetcode.com',
    'accept': '*/*',
    'accept-language': 'en,en-US;q=0.9,vi;q=0.8',
    # Already added when you pass json=
    # 'content-type': 'application/json',
    # Requests sorts cookies= alphabetically
    # 'cookie': '_ga=GA1.2.851805707.1658332963; gr_user_id=2ee6bb9f-3c50-429f-8bd6-f80f5d76d4a2; csrftoken=FOnxnVD05cdmtHX4mmKayx5290ojy5y0rlHTip49wOTbMsprVAdAIWwK519UgPjr; _gid=GA1.2.463271.1658914517; __stripe_mid=7ffe7d00-f6ab-42a0-859d-5b30ef94dbc2ba1c8c; 87b5a3c3f1a55520_gr_last_sent_cs1=tmanh17; NEW_PROBLEMLIST_PAGE=1; LEETCODE_SESSION=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfYXV0aF91c2VyX2lkIjoiMjU3MzcxMCIsIl9hdXRoX3VzZXJfYmFja2VuZCI6ImFsbGF1dGguYWNjb3VudC5hdXRoX2JhY2tlbmRzLkF1dGhlbnRpY2F0aW9uQmFja2VuZCIsIl9hdXRoX3VzZXJfaGFzaCI6IjVlY2JiY2JlMTFmMDY0YTU4ZWY1ZjJmY2Q2YmNiODNkODRmNDUwOWIiLCJpZCI6MjU3MzcxMCwiZW1haWwiOiJ0bWFuaDE3QGdtYWlsLmNvbSIsInVzZXJuYW1lIjoidG1hbmgxNyIsInVzZXJfc2x1ZyI6InRtYW5oMTciLCJhdmF0YXIiOiJodHRwczovL2Fzc2V0cy5sZWV0Y29kZS5jb20vdXNlcnMvdGllbl9tYW5oL2F2YXRhcl8xNTc5MzcxOTYxLnBuZyIsInJlZnJlc2hlZF9hdCI6MTY2MDMxMjg2NCwiaXAiOiIxNC4xNzcuMTEyLjIyOSIsImlkZW50aXR5IjoiZDNkNDA2OGExMWY0ZTBmNDRlNDUyN2IxMmZjNGI5OGYiLCJzZXNzaW9uX2lkIjoyNDc3NTA0MywiX3Nlc3Npb25fZXhwaXJ5IjoxMjA5NjAwfQ.knv3q7r4CdSjINMiFlirrGj78aj1Ftc6ksu73DDPI8g; 87b5a3c3f1a55520_gr_session_id=64f6546c-b61e-4326-b038-79296d4ace27; 87b5a3c3f1a55520_gr_last_sent_sid_with_cs1=64f6546c-b61e-4326-b038-79296d4ace27; 87b5a3c3f1a55520_gr_session_id_64f6546c-b61e-4326-b038-79296d4ace27=true; __atuvc=68%7C29%2C40%7C30%2C54%7C31%2C52%7C32; __atuvs=62f7ab8a6e718732003; c_a_u="dG1hbmgxNw==:1oMrZR:l9Zkv5EykbtDXrOuHVtKhaKE0oc"; 87b5a3c3f1a55520_gr_cs1=tmanh17',
    'origin': 'https://leetcode.com',
    'referer': 'https://leetcode.com/problemset/algorithms/?status=NOT_STARTED&page=2&difficulty=HARD&sorting=W3sic29ydE9yZGVyIjoiREVTQ0VORElORyIsIm9yZGVyQnkiOiJGUk9OVEVORF9JRCJ9XQ%3D%3D',
    'sec-ch-ua': '"Chromium";v="104", " Not A;Brand";v="99", "Google Chrome";v="104"',
    'sec-ch-ua-mobile': '?0',
    'sec-ch-ua-platform': '"macOS"',
    'sec-fetch-dest': 'empty',
    'sec-fetch-mode': 'cors',
    'sec-fetch-site': 'same-origin',
    'user-agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/104.0.0.0 Safari/537.36',
    'x-csrftoken': 'FOnxnVD05cdmtHX4mmKayx5290ojy5y0rlHTip49wOTbMsprVAdAIWwK519UgPjr',
}

json_data = {
    'query': '\n    query problemsetQuestionList($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {\n  problemsetQuestionList: questionList(\n    categorySlug: $categorySlug\n    limit: $limit\n    skip: $skip\n    filters: $filters\n  ) {\n    total: totalNum\n    questions: data {\n      acRate\n      difficulty\n      freqBar\n      frontendQuestionId: questionFrontendId\n      isFavor\n      paidOnly: isPaidOnly\n      status\n      title\n      titleSlug\n      topicTags {\n        name\n        id\n        slug\n      }\n      hasSolution\n      hasVideoSolution\n    }\n  }\n}\n    ',
    'variables': {
        'categorySlug': 'algorithms',
        'skip': 50,
        'limit': 5000,
        'filters': {
            'orderBy': 'FRONTEND_ID',
            'sortOrder': 'DESCENDING',
            'difficulty': 'HARD',
            'status': 'NOT_STARTED',
        },
    },
}
# print(1)
response = requests.post('https://leetcode.com/graphql/', cookies=cookies, headers=headers, json=json_data)
ret = response.json()

# print(ret)
cookies = {
    '_ga': 'GA1.2.851805707.1658332963',
    'gr_user_id': '2ee6bb9f-3c50-429f-8bd6-f80f5d76d4a2',
    'csrftoken': 'FOnxnVD05cdmtHX4mmKayx5290ojy5y0rlHTip49wOTbMsprVAdAIWwK519UgPjr',
    '_gid': 'GA1.2.463271.1658914517',
    '__stripe_mid': '7ffe7d00-f6ab-42a0-859d-5b30ef94dbc2ba1c8c',
    '87b5a3c3f1a55520_gr_last_sent_cs1': 'tmanh17',
    'NEW_PROBLEMLIST_PAGE': '1',
    'LEETCODE_SESSION': 'eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfYXV0aF91c2VyX2lkIjoiMjU3MzcxMCIsIl9hdXRoX3VzZXJfYmFja2VuZCI6ImFsbGF1dGguYWNjb3VudC5hdXRoX2JhY2tlbmRzLkF1dGhlbnRpY2F0aW9uQmFja2VuZCIsIl9hdXRoX3VzZXJfaGFzaCI6IjVlY2JiY2JlMTFmMDY0YTU4ZWY1ZjJmY2Q2YmNiODNkODRmNDUwOWIiLCJpZCI6MjU3MzcxMCwiZW1haWwiOiJ0bWFuaDE3QGdtYWlsLmNvbSIsInVzZXJuYW1lIjoidG1hbmgxNyIsInVzZXJfc2x1ZyI6InRtYW5oMTciLCJhdmF0YXIiOiJodHRwczovL2Fzc2V0cy5sZWV0Y29kZS5jb20vdXNlcnMvdGllbl9tYW5oL2F2YXRhcl8xNTc5MzcxOTYxLnBuZyIsInJlZnJlc2hlZF9hdCI6MTY2MDMxMjg2NCwiaXAiOiIxNC4xNzcuMTEyLjIyOSIsImlkZW50aXR5IjoiZDNkNDA2OGExMWY0ZTBmNDRlNDUyN2IxMmZjNGI5OGYiLCJzZXNzaW9uX2lkIjoyNDc3NTA0MywiX3Nlc3Npb25fZXhwaXJ5IjoxMjA5NjAwfQ.knv3q7r4CdSjINMiFlirrGj78aj1Ftc6ksu73DDPI8g',
    '87b5a3c3f1a55520_gr_session_id': '64f6546c-b61e-4326-b038-79296d4ace27',
    '87b5a3c3f1a55520_gr_last_sent_sid_with_cs1': '64f6546c-b61e-4326-b038-79296d4ace27',
    '87b5a3c3f1a55520_gr_session_id_64f6546c-b61e-4326-b038-79296d4ace27': 'true',
    '__atuvc': '68%7C29%2C40%7C30%2C54%7C31%2C52%7C32',
    '__atuvs': '62f7ab8a6e718732003',
    '87b5a3c3f1a55520_gr_cs1': 'tmanh17',
    'c_a_u': '"dG1hbmgxNw==:1oMrdd:hgevPQqHVLMan5_8mYNd23YS4BE"',
    '_gat': '1',
}

headers = {
    'authority': 'leetcode.com',
    'accept': '*/*',
    'accept-language': 'en,en-US;q=0.9,vi;q=0.8',
    # Already added when you pass json=
    # 'content-type': 'application/json',
    # Requests sorts cookies= alphabetically
    # 'cookie': '_ga=GA1.2.851805707.1658332963; gr_user_id=2ee6bb9f-3c50-429f-8bd6-f80f5d76d4a2; csrftoken=FOnxnVD05cdmtHX4mmKayx5290ojy5y0rlHTip49wOTbMsprVAdAIWwK519UgPjr; _gid=GA1.2.463271.1658914517; __stripe_mid=7ffe7d00-f6ab-42a0-859d-5b30ef94dbc2ba1c8c; 87b5a3c3f1a55520_gr_last_sent_cs1=tmanh17; NEW_PROBLEMLIST_PAGE=1; LEETCODE_SESSION=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfYXV0aF91c2VyX2lkIjoiMjU3MzcxMCIsIl9hdXRoX3VzZXJfYmFja2VuZCI6ImFsbGF1dGguYWNjb3VudC5hdXRoX2JhY2tlbmRzLkF1dGhlbnRpY2F0aW9uQmFja2VuZCIsIl9hdXRoX3VzZXJfaGFzaCI6IjVlY2JiY2JlMTFmMDY0YTU4ZWY1ZjJmY2Q2YmNiODNkODRmNDUwOWIiLCJpZCI6MjU3MzcxMCwiZW1haWwiOiJ0bWFuaDE3QGdtYWlsLmNvbSIsInVzZXJuYW1lIjoidG1hbmgxNyIsInVzZXJfc2x1ZyI6InRtYW5oMTciLCJhdmF0YXIiOiJodHRwczovL2Fzc2V0cy5sZWV0Y29kZS5jb20vdXNlcnMvdGllbl9tYW5oL2F2YXRhcl8xNTc5MzcxOTYxLnBuZyIsInJlZnJlc2hlZF9hdCI6MTY2MDMxMjg2NCwiaXAiOiIxNC4xNzcuMTEyLjIyOSIsImlkZW50aXR5IjoiZDNkNDA2OGExMWY0ZTBmNDRlNDUyN2IxMmZjNGI5OGYiLCJzZXNzaW9uX2lkIjoyNDc3NTA0MywiX3Nlc3Npb25fZXhwaXJ5IjoxMjA5NjAwfQ.knv3q7r4CdSjINMiFlirrGj78aj1Ftc6ksu73DDPI8g; 87b5a3c3f1a55520_gr_session_id=64f6546c-b61e-4326-b038-79296d4ace27; 87b5a3c3f1a55520_gr_last_sent_sid_with_cs1=64f6546c-b61e-4326-b038-79296d4ace27; 87b5a3c3f1a55520_gr_session_id_64f6546c-b61e-4326-b038-79296d4ace27=true; __atuvc=68%7C29%2C40%7C30%2C54%7C31%2C52%7C32; __atuvs=62f7ab8a6e718732003; 87b5a3c3f1a55520_gr_cs1=tmanh17; c_a_u="dG1hbmgxNw==:1oMrdd:hgevPQqHVLMan5_8mYNd23YS4BE"; _gat=1',
    'origin': 'https://leetcode.com',
    'referer': 'https://leetcode.com/problems/naming-a-company/',
    'sec-ch-ua': '"Chromium";v="104", " Not A;Brand";v="99", "Google Chrome";v="104"',
    'sec-ch-ua-mobile': '?0',
    'sec-ch-ua-platform': '"macOS"',
    'sec-fetch-dest': 'empty',
    'sec-fetch-mode': 'cors',
    'sec-fetch-site': 'same-origin',
    'user-agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/104.0.0.0 Safari/537.36',
    'x-csrftoken': 'FOnxnVD05cdmtHX4mmKayx5290ojy5y0rlHTip49wOTbMsprVAdAIWwK519UgPjr',
    'x-newrelic-id': 'UAQDVFVRGwEAXVlbBAg=',
}
cnt = 0
print("Questions: ", len(ret['data']['problemsetQuestionList']['questions']))
for p in ret['data']['problemsetQuestionList']['questions']:
    # print(3)
    import time
    # time.sleep(1)
    if (p['paidOnly'] == True):
        continue

    json_data = {
        'operationName': 'questionData',
        'variables': {
            'titleSlug': 'naming-a-company',
        },
        'query': 'query questionData($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    questionId\n    questionFrontendId\n    boundTopicId\n    title\n    titleSlug\n    content\n    translatedTitle\n    translatedContent\n    isPaidOnly\n    difficulty\n    likes\n    dislikes\n    isLiked\n    similarQuestions\n    exampleTestcases\n    categoryTitle\n    contributors {\n      username\n      profileUrl\n      avatarUrl\n      __typename\n    }\n    topicTags {\n      name\n      slug\n      translatedName\n      __typename\n    }\n    companyTagStats\n    codeSnippets {\n      lang\n      langSlug\n      code\n      __typename\n    }\n    stats\n    hints\n    solution {\n      id\n      canSeeDetail\n      paidOnly\n      hasVideoSolution\n      paidOnlyVideo\n      __typename\n    }\n    status\n    sampleTestCase\n    metaData\n    judgerAvailable\n    judgeType\n    mysqlSchemas\n    enableRunCode\n    enableTestMode\n    enableDebugger\n    envInfo\n    libraryUrl\n    adminUrl\n    challengeQuestion {\n      id\n      date\n      incompleteChallengeCount\n      streakCount\n      type\n      __typename\n    }\n    __typename\n  }\n}\n',
    }
    json_data['variables']['titleSlug'] = p['titleSlug'];
    problem = {}
    problem['title'] = p['titleSlug']
    topicTags = []
    for topic in p['topicTags']:
        topicTags.append(topic['name'])
    problem['topicTags'] = topicTags

    response = requests.post('https://leetcode.com/graphql', cookies=cookies, headers=headers, json=json_data).json()

    # print(response)
    import json
    problem['dislikes'] = response['data']['question']['dislikes']
    problem['likes'] = response['data']['question']['likes']
    problem['totalAccepted'] = json.loads(response['data']['question']['stats'])['totalAcceptedRaw']
    problem['totalSubmission'] = json.loads(response['data']['question']['stats'])['totalSubmissionRaw']
    problem['totalAcceptedRate'] = problem['totalAccepted']/problem['totalSubmission']
    sourceFile = open('leetcodehard.txt', 'a')
    print(json.dumps(problem), file = sourceFile)
    cnt += 1
    print(cnt)
sourceFile.close() 