package me.kyeongho.repository.support;

import static me.kyeongho.entity.QMember.member;
import static me.kyeongho.entity.QTeam.team;
import static org.springframework.util.StringUtils.hasText;

import java.util.List;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.support.PageableExecutionUtils;
import org.springframework.stereotype.Repository;
import org.springframework.util.StringUtils;

import com.querydsl.core.types.dsl.BooleanExpression;
import com.querydsl.jpa.impl.JPAQuery;

import me.kyeongho.dto.MemberSearchCondition;
import me.kyeongho.entity.Member;
import me.kyeongho.entity.QTeam;

@Repository
public class MemberTestRepository extends Querydsl4RepositorySupport{

	public MemberTestRepository() {
		super(Member.class);
		// TODO Auto-generated constructor stub
	}
	
	public List<Member> basicSelect() {
		return select(member)
				.from(member)
				.fetch();
	}
	
	public List<Member> basicSelectFrom() {
		return selectFrom(member)
				.fetch();
	}
	
	public Page<Member> searchPageByApplyPage(MemberSearchCondition condition, Pageable pageable) {
		JPAQuery<Member> query = selectFrom(member)
				.leftJoin(member.team, team)
				.where(usernameEq(condition.getUsername()),
						teamNameEq(condition.getTeamName()),
						ageGoe(condition.getAgeGoe()),
						ageLoe(condition.getAgeLoe()));
		
		return PageableExecutionUtils.getPage(query.fetch(), pageable, () -> query.fetchCount());
	}
	
	public Page<Member> applyPagination(MemberSearchCondition condition, Pageable pageable) {
		return applyPagination(pageable, contentQuery -> 
						contentQuery.selectFrom(member)
							.leftJoin(member.team, team)
									.where(usernameEq(condition.getUsername()),
											teamNameEq(condition.getTeamName()),
											ageGoe(condition.getAgeGoe()),
											ageLoe(condition.getAgeLoe())),
									countQuery -> 
									countQuery.selectFrom(member)
									.leftJoin(member.team, team)
									.where(usernameEq(condition.getUsername()),
											teamNameEq(condition.getTeamName()),
											ageGoe(condition.getAgeGoe()),
											ageLoe(condition.getAgeLoe())));
	}
	
	private BooleanExpression usernameEq(String username) {
		return hasText(username) ? member.username.eq(username) : null;
	}
	private BooleanExpression teamNameEq(String teamName) {
		return hasText(teamName) ? team.name.eq(teamName) : null;
	}
	private BooleanExpression ageGoe(Integer ageGoe) {
		return ageGoe != null ? member.age.goe(ageGoe) : null;
	}
	private BooleanExpression ageLoe(Integer ageLoe) {
		return ageLoe != null ? member.age.loe(ageLoe) : null;
	}
}
